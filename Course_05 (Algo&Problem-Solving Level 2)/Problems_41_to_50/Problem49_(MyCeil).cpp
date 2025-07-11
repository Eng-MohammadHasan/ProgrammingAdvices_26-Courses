#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyCeil(float Number)
{
	// Better Solution :-)

	/*int IntPart = int(Number);

	if (Number == IntPart)
	{
		return IntPart;
	}
	else
	{
		if (Number >= 0)
		{
			return ++IntPart;
		}
		else
		{
			return IntPart;
		}

	}*/

	if (abs(GetFractionPart(Number)) > 0)
	{
		if (Number > 0)
		{
			return int(Number) + 1;
		}
		else
		{
			return int(Number);
		}
	}
	else
	{
		return Number; // If the number is already an integer, return it as is.
	}

}

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter a number :\n";
	cin >> Number;

	return Number;
}

int main()
{
	float Number = ReadNumber();
	cout << "My Ceil Result : " << MyCeil(Number) << endl;

	cout << "C++ Ceil Result : " << ceil(Number) << endl;

	return 0;
}