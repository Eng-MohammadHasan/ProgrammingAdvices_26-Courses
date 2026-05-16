#include <iostream>
using namespace std;

bool IsLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisble by 400 
	// then it is a leap year
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

unsigned short DayOfWeekOrder(unsigned short Day, unsigned short Month, unsigned short Year)
{
	unsigned short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sun , 1:Mon , 2:Tue...etc

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(unsigned short DayOfWeekOrder)
{
	string arrDayNames[] = {
		"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

unsigned short NumberOfDaysInAMonth(unsigned short Month, unsigned short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	unsigned short DaysInEachMonth[12] = { 31, 28 , 31 ,  30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 ,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

string MonthShortName(unsigned short MonthNumber)
{
	string Months[12] = { "Jan" , "Feb" , "Mar",
						  "Apr" , "May" , "Jun",
						  "Jul" , "Aug" , "Sep",
						  "Oct" , "Nov" , "Dec",
	};

	return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(unsigned short Month, unsigned short Year)
{
	unsigned short NumberOfDays;

	// Index of the day from 0 to 6
	unsigned short current = DayOfWeekOrder(1, Month, Year);

	NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	// Print the current month name
	printf("\n  _______________%s_______________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces 
	int i;
	for (i = 0; i < current; i++)
	{
		printf("     "); // Printing Space Sets
	}

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n  _________________________________\n");
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a month (1 - 12)? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a year? ";
	cin >> Year;

	return Year;
}

int main()
{
	unsigned short Month, Year;

	Year = ReadYear();
	Month = ReadMonth();

	PrintMonthCalendar(Month, Year);

	system("pause>0");
	return 0;
}
