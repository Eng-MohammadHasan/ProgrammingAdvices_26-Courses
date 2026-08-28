#include <iostream>
#include <string>

using namespace std;
// NOTE : Weekends are excluded :)

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

bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;
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

unsigned short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
	// the instructor names the variable like this 
	//unsigned short DaysCount = 0;

	unsigned short TotalVacationDays = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			TotalVacationDays++;
		
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return TotalVacationDays;
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
	cout << "\nVacation Starts:";
	sDate DateFrom = ReadFullDate();

	cout << "\nVacation Ends:";
	sDate DateTo = ReadFullDate();

	cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "
		<< DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "Vacation To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , "
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);

	system("pause>0");
	return 0;
}
