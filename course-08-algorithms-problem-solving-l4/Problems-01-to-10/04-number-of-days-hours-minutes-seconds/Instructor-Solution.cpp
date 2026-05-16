#include <iostream>
using namespace std;

bool isLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if years is divisble by 400 
	// then it is a leap year
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

unsigned short NumberOfDaysInAYear(unsigned short Year)
{
	return isLeapYear(Year) ? 366 : 365;
}

unsigned short NumberOfHoursInAYear(unsigned short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

unsigned int NumberOfMinutesInAYear(unsigned short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}

unsigned int NumberOfSecondsInAYear(unsigned short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
}

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

	cout << "\nNumber of Days    in Year [" << Year << "] is "
		<< NumberOfDaysInAYear(Year);

	cout << "\nNumber of Hours   in Year [" << Year << "] is "
		<< NumberOfHoursInAYear(Year);

	cout << "\nNumber of Minutes in Year [" << Year << "] is "
		<< NumberOfMinutesInAYear(Year);

	cout << "\nNumber of Seconds in Year [" << Year << "] is "
		<< NumberOfSecondsInAYear(Year);

	system("pause>0");
	return 0;
}

