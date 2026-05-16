#include <iostream>
using namespace std;

enum enMonths
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};

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

string GetMonthName(enMonths Month)
{
	switch (Month)
	{
	case enMonths::January:
		return "Jan";

	case enMonths::February:
		return "Feb";

	case enMonths::March:
		return "March";

	case enMonths::April:
		return "April";

	case enMonths::May:
		return "May";

	case enMonths::June:
		return "June";

	case enMonths::July:
		return "July";

	case enMonths::August:
		return "Aug";

	case enMonths::September:
		return "Sep";

	case enMonths::October:
		return "Oct";

	case enMonths::November:
		return "Nov";

	case enMonths::December:
		return "Dec";
	}
}

void PrintMonthCalendar(unsigned short Month, unsigned short Year)
{
	unsigned short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	// Index of the day from 0 to 6
	unsigned short FirstDayInMonth = DayOfWeekOrder(1, Month, Year);


	// Print the current month name
	printf("\n________________%s________________\n\n",
		GetMonthName((enMonths)Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces 
	int i;
	for (i = 0; i < FirstDayInMonth; i++)
	{
		printf("     ");
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

	printf("\n -----------------------------------\n");
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

	Month = ReadMonth();
	Year = ReadYear();

	PrintMonthCalendar(Month, Year);

	system("pause>0");
	return 0;
}
