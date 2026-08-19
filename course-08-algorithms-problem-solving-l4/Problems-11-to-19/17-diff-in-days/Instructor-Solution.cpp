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

bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2)
{
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
			(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

	//return (Date1.Year != Date2.Year) ? Date1.Year < Date2.Year :
	//	(Date1.Month != Date2.Month) ? Date1.Month < Date2.Month :
	//	Date1.Day < Date2.Day;
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

unsigned short GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	unsigned short Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
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
	sDate Date2 = ReadFullDate();

	cout << "\nDifference is: " 
		<< GetDifferenceInDays(Date1, Date2) << " Day(s).";

	cout << "\nDifference (Including End Day) is: " 
		<< GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

	system("pause>0");
	return 0;
}
