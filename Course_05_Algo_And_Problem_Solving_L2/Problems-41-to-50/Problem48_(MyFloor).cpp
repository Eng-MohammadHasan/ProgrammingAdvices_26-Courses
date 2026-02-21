#include <iostream>
#include <cmath>

using namespace std;

/* Another solution :-)

int MyFloorFunction(float Number) {
	if (Number >= 0 || Number == IntPart)
	{
		return IntPart;
	}
	else
	{
		return --IntPart;
	}
 }

*/

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

int MyFloor(float Number)
{
	int IntPart = int(Number);

	if (Number >= 0)
	{
		return IntPart;
	}
	else
	{
		// If there's a fraction in the number 
		if (GetFractionPart(Number) != 0.0f)
		{
			return --IntPart;
		}
		else
		{
			return IntPart;
		}

	}
}

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter a float number :\n";
	cin >> Number;

	return Number;
}

int main()
{
	float Number = ReadNumber();
	cout << "My Floor Result : " << MyFloor(Number) << endl;

	cout << "C++ Floor Result : " << floor(Number) << endl;

	return 0;
}