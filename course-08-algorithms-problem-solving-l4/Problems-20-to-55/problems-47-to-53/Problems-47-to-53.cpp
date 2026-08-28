#pragma warning (disable:4996)

#include <iostream>
#include <string>

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
	// OR if year is divisble by 400 
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

unsigned short GetDifferenceInDays(const sDate& Date1, const sDate& Date2, bool IncludeEndDay = false)
{
	unsigned short TotalDays = 0;
	sDate TempDate = Date1; // make a copy since Date1 is const

	// Add full years between Date1 and Date2
	while (TempDate.Year < Date2.Year)
	{
		TotalDays += NumberOfDaysInAYear(TempDate.Year);
		TempDate.Year++;
	}

	if (IncludeEndDay)
	{
		return TotalDays + NumberOfDaysFromTheBeginningOfTheYear(Date2) + 1
			- NumberOfDaysFromTheBeginningOfTheYear(Date1);
	}

	return TotalDays + NumberOfDaysFromTheBeginningOfTheYear(Date2)
		- NumberOfDaysFromTheBeginningOfTheYear(Date1);
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

// Overloading
unsigned short DayOfWeekOrder(const sDate& Date)
{
	// Instead of duplicating the calculation above,
	// call the first function using the values stored in the Date object.
	// This avoids code duplication and makes refactoring easier.
	// If the calculation changes later, we only need to modify it in one place.
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(unsigned short DayOfWeekOrder)
{
	string arrDayNames[] = {
		"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(const sDate& Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekend(const sDate& Date)
{
	// Weekends are Fri and Sat
	unsigned short DayOrderIndex = DayOfWeekOrder(Date);
	return (DayOrderIndex == 5 || DayOrderIndex == 6);
}

bool IsBusinessDay(const sDate& Date)
{
	//Weekdays are Sun,Mon,Tue,Wed and Thur
	
	/*
		unsigned short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex >= 0 && DayIndex <= 4);
	*/

	//shorter method is to invert the IsWeekEnd: this will save updating code
	return !IsWeekend(Date);
}

unsigned short DaysUntilTheEndOfWeek(const sDate& Date)
{
	return 6 - DayOfWeekOrder(Date);
}

unsigned short DaysUntilTheEndOfMonth(const sDate& Date1)
{
	sDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date1.Month , Date1.Year);
	EndOfMonthDate.Month = Date1.Month;
	EndOfMonthDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfMonthDate , true);
	
	//return NumberOfDaysInAMonth(Date1.Month, Date1.Year) - Date1.Day;
}

unsigned short DaysUntilTheEndOfYear(const sDate& Date1)
{
	sDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfYearDate, true);

	//return NumberOfDaysInAYear(Date.Year) - NumberOfDaysFromTheBeginningOfTheYear(Date);
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

sDate GetSystemDate()
{
	sDate Date;

	// Deals with date-time library 
	time_t t = time(0); // get time now 
	tm* now = localtime(&t); // here it will return structure of several components 

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int main()
{
	sDate Date1 = GetSystemDate();

	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1)) 
		<< " , "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year
		<< endl;

	//---------------------------
	cout << "\nIs it End of Week?\n";
	
	if (IsEndOfWeek(Date1))
		cout << "Yes it is Saturday , it's end of Week.";
	else
		cout << "No it's Not end of week.";
	
	//---------------------------
	cout << "\n\nIs it Weekend?\n";

	if (IsWeekend(Date1))
		cout << "Yes it is weekend.";
	else
		cout << "No today is " <<
		DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";
	
	//---------------------------
	cout << "\n\nIs it Business Day?\n";

	if (IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it's NOT a business day.";
	
	//---------------------------
	cout << "\n\nDays until end of week : " 
		<< DaysUntilTheEndOfWeek(Date1) << " Day(s).";
	
	//---------------------------
	cout << "\n\nDays until end of month : " 
		<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";
	
	//---------------------------
	cout << "\n\nDays until end of year : " 
		<< DaysUntilTheEndOfYear(Date1) << " Day(s).";
	
	system("pause>0");
	return 0;
}