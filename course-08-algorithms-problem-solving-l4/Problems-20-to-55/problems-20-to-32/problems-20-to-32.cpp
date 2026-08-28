#include <iostream>
using namespace std;

struct sDate
{
	unsigned short Year;
	unsigned short Month;
	unsigned short Day;
};

bool IsLeapYear(unsigned short Year)
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

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

bool IsLastDayInMonth(const sDate& Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(unsigned short Month)
{
	return (Month == 12);
}

sDate CorrectDateDay(sDate& Date)
{
	unsigned short NumberOfDaysInCurrentMonth =
		NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate IncreaseDateByOneDay(sDate& Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

sDate IncreaseDateByXDays(unsigned short Days, sDate& Date)
{
	for (unsigned short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

sDate IncreaseDateByOneWeek(sDate& Date)
{
	/*
		for (unsigned short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
	*/

	// Or 
	Date = IncreaseDateByXDays(7, Date);
	return Date;
}

sDate IncreaseDateByXWeeks(unsigned short Weeks, sDate& Date)
{
	for (unsigned short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

sDate IncreaseDateByOneMonth(sDate& Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	// last check day in date should not exceed max days in the current month
	// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022,
	// it should be 28/2/2022
	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByXMonths(unsigned short Months, sDate& Date)
{
	for (unsigned short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

sDate IncreaseDateByOneYear(sDate& Date)
{
	Date.Year++;

	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByXYears(unsigned short Years, sDate& Date)
{
	for (unsigned short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

sDate IncreaseDateByXYearsFaster(unsigned short Years, sDate& Date)
{
	Date.Year += Years;

	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByOneDecade(sDate& Date)
{
	// Period of 10 years 
	Date.Year += 10;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByXDecades(unsigned short Decades, sDate& Date)
{
	for (unsigned short i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadesFaster(unsigned short Decades, sDate& Date)
{
	Date.Year += Decades * 10;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByOneCentury(sDate& Date)
{
	// Period of 100 years 
	Date.Year += 100;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate IncreaseDateByOneMillennium(sDate& Date)
{
	// Period of 1000 years 
	Date.Year += 1000;
	Date = CorrectDateDay(Date);

	return Date;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a Year: ";
	cin >> Year;

	return Year;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "Please enter a Month (1-12): ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

unsigned short ReadDay(unsigned short Month, unsigned short Year)
{
	unsigned short Day;
	unsigned short MaximumDays = NumberOfDaysInAMonth(Month, Year);

	do
	{
		cout << "Please enter Day (1 - " << MaximumDays << "): ";
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

int main()
{
	sDate Date1 = ReadFullDate();

	cout << "\nDate After: \n";

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(10, Date1);
	cout << "\n02-Adding 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonths(5, Date1);
	cout << "\n06-Adding 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Adding 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecades(10, Date1);
	cout << "\n11-Adding 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Adding 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}