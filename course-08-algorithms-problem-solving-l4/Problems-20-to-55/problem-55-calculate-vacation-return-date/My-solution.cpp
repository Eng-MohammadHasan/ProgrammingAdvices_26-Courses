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

sDate CalculateVacationReturnDate(sDate DateFrom , unsigned short VacationDays)
{
	while (VacationDays > 0)
	{
		if (IsBusinessDay(DateFrom))
			VacationDays--;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}


	//in case the return date is weekend keep adding one day util you reach business day
	while (IsWeekend(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
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

unsigned short ReadVacationDays()
{
	unsigned short Days;

	cout << "\nPlease enter vacation days? ";
	cin >> Days;

	return Days;
}

int main()
{
	cout << "\nVacation Starts:";
	sDate DateFrom = ReadFullDate();

	unsigned short VacationDays = ReadVacationDays();

	sDate ReturnDate = CalculateVacationReturnDate(DateFrom , VacationDays);

	cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate)) << " , "
		<< ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

	system("pause>0");
	return 0;
}
