#include <iostream>
using namespace std;

bool IsLeapYear(unsigned short Year)
{
	// leap year if perfectly divisible by 400
	if (Year % 400 == 0)
	{
		return true;
	}

	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (Year % 100 == 0)
	{
		return false;
	}
	// leap year if not divisible by 100 
	// but divisible by 4 
	else if (Year % 4 == 0)
	{
		return true;
	}
	// all the other years are not leap years
	else
	{
		return false;
	}
}

// or just ...
//bool IsLeapYear(unsigned short Year)
//{
//	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
//}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

int main()
{
	unsigned short Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else
	{
		cout << "\nNO, Year [" << Year << "] is NOT a leap year.\n";
	}

	system("pause>0");
	return 0;
}
