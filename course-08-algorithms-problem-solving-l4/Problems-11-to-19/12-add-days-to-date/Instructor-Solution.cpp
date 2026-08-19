#include <iostream>
using namespace std;

struct sDate
{
	unsigned short Day;
	unsigned short Month;
	unsigned short Year;
};

bool isLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

unsigned short NumberOfDaysInAMonth(unsigned short Month, unsigned short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	const unsigned short DaysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

unsigned short NumberOfDaysFromTheBeginningOfTheYear(unsigned short Day, unsigned short Month, unsigned short Year)
{
	unsigned short TotalDays = 0;

	for (int i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

sDate DateAddDays(unsigned short DaysToAdd, sDate Date)
{
	unsigned short RemainingDays = DaysToAdd + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	unsigned short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a Month (1-12): ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a Year: ";
	cin >> Year;

	return Year;
}

unsigned short ReadDay(unsigned short Month, unsigned short Year)
{
	unsigned short Day;
	unsigned short MaximumDays = NumberOfDaysInAMonth(Month, Year);

	do
	{
		cout << "\nPlease enter Day (1 - " << MaximumDays << "): ";
		cin >> Day;

	} while (Day < 1 || Day > MaximumDays);

	return Day;
}

sDate ReadFullDate()
{
	sDate Date;

	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay(Date.Month, Date.Year);

	return Date;
}

unsigned short ReadDaysToAdd()
{
	unsigned short Days;

	cout << "\nHow many days to add? ";
	cin >> Days;

	return Days;
}

int main()
{
	sDate Date = ReadFullDate();
	unsigned short DaysToAdd = ReadDaysToAdd();

	Date = DateAddDays(DaysToAdd, Date);
	cout << "\nDate after adding [" << DaysToAdd << "] days is: "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";

	system("pause>0");
	return 0;
}
