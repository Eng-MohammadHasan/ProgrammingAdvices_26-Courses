#include <iostream>
using namespace std;

bool IsLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if years is divisble by 400 
	// then it is a leap year
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

unsigned short NumberOfDaysInAMonth(unsigned short Month, unsigned short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	unsigned short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (unsigned short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
		{
			return 31;
		}
	}

	// if you reach here then its 30 days. 
	return 30;
}

unsigned short NumberOfHoursInAMonth(unsigned short Month, unsigned short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}

unsigned int NumberOfMinutesInAMonth(unsigned short Month, unsigned short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}

unsigned int NumberOfSecondsInAMonth(unsigned short Month, unsigned short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a Month (1-12) : ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

int main()
{
	unsigned short Year, Month;

	Year = ReadYear();
	Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is : "
		<< NumberOfDaysInAMonth(Month, Year);

	cout << "\nNumber of Hours   in Month [" << Month << "] is : "
		<< NumberOfHoursInAMonth(Month, Year);

	cout << "\nNumber of Minutes in Month [" << Month << "] is : "
		<< NumberOfMinutesInAMonth(Month, Year);

	cout << "\nNumber of Seconds in Month [" << Month << "] is : "
		<< NumberOfSecondsInAMonth(Month, Year);

	cout << endl;

	system("pause>0");
	return 0;
}
