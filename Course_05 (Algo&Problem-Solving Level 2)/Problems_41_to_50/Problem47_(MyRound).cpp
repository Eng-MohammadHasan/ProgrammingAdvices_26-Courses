#include <iostream>
#include <cmath>

using namespace std;

/* This solution is the standard version : -)

float MyRound(float Number)
{
	if (Number >= 0)
		return int(Number + 0.5f);
	else
		return int(Number - 0.5f);
}

*/

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

int MyRound(float Number)
{
	int IntPart = int(Number);

	float FractionsPart = GetFractionPart(Number);

	// If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
	if (abs(FractionsPart) >= 0.5f)
	{
		// If the number is positive, round up.
		if (Number > 0)
		{
			return ++IntPart;
		}
		// If the number is negative, round down.
		else
		{
			return --IntPart;
		}
	}
	// If the fractional part is less than 0.5, keep the integer part as it is.
	else
	{
		return IntPart;
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
	cout << "My Round Result : " << MyRound(Number) << endl;

	cout << "C++ Round Result : " << round(Number) << endl;

	return 0;
}