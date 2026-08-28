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

sDate DecreaseDateByOneDay(sDate& Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;	
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

sDate DecreaseDateByXDays(unsigned short Days, sDate& Date)
{
	for (unsigned short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

sDate DecreaseDateByOneWeek(sDate& Date)
{
	//for (unsigned short i = 1; i <= 7; i++)
	//{
	//	Date = DecreaseDateByOneDay(Date);
	//}

	Date = DecreaseDateByXDays(7, Date);

	return Date;
}

sDate DecreaseDateByXWeeks(unsigned short Weeks, sDate& Date)
{
	for (unsigned short i = 1; i <= Weeks;i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	
	return Date;
}

sDate DecreaseDateByOneMonth(sDate& Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	
		//last check day in date should not exceed max days in the current month
		// example if date is 31/3/2022 decreasing one month should not be 31 / 2 / 2022,
		// it should be 28/2/2022
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByXMonths(unsigned short Months , sDate& Date)
{
	for (unsigned short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

sDate DecreaseDateByOneYear(sDate& Date)
{
	Date.Year--;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByXYears(unsigned short Years , sDate& Date)
{
	for (unsigned short i = 1; i <= Years ;i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

sDate DecreaseDateByXYearsFaster(unsigned short Years, sDate& Date)
{
	Date.Year -= Years;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByOneDecade(sDate& Date)
{
	// Period of 10 years 
	Date.Year -= 10;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByXDecades(unsigned short Decades, sDate& Date)
{
	for (unsigned short i = 1; i <= Decades * 10 ; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

sDate DecreaseDateByXDecadesFaster(unsigned short Decades, sDate& Date)
{
	Date.Year -= (Decades * 10);
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByOneCentury(sDate& Date)
{
	// Period of 100 years
	Date.Year -= 100;
	Date = CorrectDateDay(Date);

	return Date;
}

sDate DecreaseDateByOneMillennium(sDate& Date)
{
	// Period of 1000 years
	Date.Year -= 1000;
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

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(10, Date1);
	cout << "\n02-Subtracting 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Subtracting 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Subtracting 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYears(10, Date1);
	cout << "\n08-Subtracting 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Subtracting 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecades(10, Date1);
	cout << "\n11-Subtracting 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Subtracting 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
		
	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}
