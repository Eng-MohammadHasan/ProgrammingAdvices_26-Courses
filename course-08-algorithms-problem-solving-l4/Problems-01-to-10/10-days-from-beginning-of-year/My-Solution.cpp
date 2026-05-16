#include <iostream>
using namespace std;

bool isLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

unsigned short NumberOfDaysInAMonth(unsigned short Month , unsigned short Year)
{
	if (Month < 1 || Month > 12)
		return 0;
	
	unsigned short DaysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

unsigned short NumberOfDaysFromTheBeginningOfTheYear(unsigned short Day, unsigned short Month, unsigned short Year)
{
	unsigned short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

unsigned short ReadDay()
{
	unsigned short Day;

	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a Month? ";
		cin >> Month;

	} while (Month < 1  || Month > 12);

	return Month;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a Year? ";
	cin >> Year;

	return Year;
}

int main()
{
	unsigned short Day = ReadDay();
	unsigned short Month = ReadMonth();
	unsigned short Year = ReadYear();

	cout << "\nNumber of Days from the beginning of the year is "
		<< NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year) << endl << endl;

	system("pause");
	return 0;
}