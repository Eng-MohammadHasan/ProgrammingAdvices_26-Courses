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

unsigned short NumberOfDaysInAYear(unsigned short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

unsigned short NumberOfDaysFromTheBeginningOfTheYear(const sDate& Date)
{
	unsigned short TotalDays = 0;

	for (int i = 1; i < Date.Month; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Date.Year);
	}

	TotalDays += Date.Day;

	return TotalDays;
}

bool IsDate1EqualDate2(const sDate& Date1, const sDate& Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;

	//return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

short GetDateDifferenceInDays(const sDate& Date1, const sDate& Date2, bool IncludeEndDay = false)
{
	short Days = 0;
	if (IsDate1EqualDate2(Date1, Date2)) return IncludeEndDay ? ++Days : Days;
	
	sDate TempDate1 = Date1; 
	while (TempDate1.Year < Date2.Year)
	{
		Days += NumberOfDaysInAYear(TempDate1.Year);
		TempDate1.Year++;
	}
		
	if (TempDate1.Year == Date2.Year)
	{
		Days += NumberOfDaysFromTheBeginningOfTheYear(Date2) - 
			    NumberOfDaysFromTheBeginningOfTheYear(Date1);

		return IncludeEndDay ? ++Days : Days;
	}

	sDate TempDate2 = Date2;
	while (TempDate2.Year < Date1.Year)
	{
		Days -= NumberOfDaysInAYear(TempDate2.Year);
		TempDate2.Year++;
	}

	if (TempDate2.Year == Date1.Year)
	{
		Days -= NumberOfDaysFromTheBeginningOfTheYear(Date2) -
			    NumberOfDaysFromTheBeginningOfTheYear(Date1);

		return IncludeEndDay ? --Days : Days;
	}
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
	sDate Date1, Date2;

	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	cout << "\n\nDifference is: " << GetDateDifferenceInDays(Date1, Date2) << " Day(s).";
	cout << "\nDifference (Including End Day) is: " << GetDateDifferenceInDays(Date1, Date2, true) << " Day(s).";

	system("pause>0");
	return 0;
}
