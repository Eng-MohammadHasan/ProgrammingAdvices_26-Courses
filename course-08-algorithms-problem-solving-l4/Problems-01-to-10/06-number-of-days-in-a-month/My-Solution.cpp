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

	unsigned short DaysInEachMonth[12] = { 31, 28 , 31 ,  30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 ,31 };

	/*if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	return DaysInEachMonth[Month - 1];*/

	//return (Month == 2 && IsLeapYear(Year) ? 29 : DaysInEachMonth[Month - 1]);

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
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

	cout << "\nNumber of Days in Month [" << Month << "] is : "
		<< NumberOfDaysInAMonth(Month, Year);

	cout << endl;

	system("pause>0");
	return 0;
}


