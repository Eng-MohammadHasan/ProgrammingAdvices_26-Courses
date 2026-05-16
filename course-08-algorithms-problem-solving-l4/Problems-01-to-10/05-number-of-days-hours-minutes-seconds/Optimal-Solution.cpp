#include <iostream>
#include <iomanip>

using namespace std;

const unsigned short HoursInADay = 24;
const unsigned short MinutesInAnHour = 60;
const unsigned short SecondsInAMinute = 60;

string Months[] =
{
	"" ,
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

struct sMonthTimeDuration
{
	unsigned short Month;
	unsigned short Days;
	unsigned short Hours;
	unsigned int Minutes;
	unsigned int Seconds;
};

bool IsLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if years is divisible by 400 
	// then it is a leap year
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

// <-- Updated function using your array logic
unsigned short NumberOfDaysInAMonth(unsigned short Year, unsigned short Month)
{
	int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (Month == 2 && IsLeapYear(Year))
		return 29;

	return DaysInMonth[Month - 1];
}

unsigned short NumberOfHoursInAMonth(unsigned short Year, unsigned short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * HoursInADay;
}

unsigned int NumberOfMinutesInAMonth(unsigned short Year, unsigned short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * MinutesInAnHour;
}

unsigned int NumberOfSecondsInAMonth(unsigned short Year, unsigned short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * SecondsInAMinute;
}

sMonthTimeDuration CalculateMonthTimeDuration(unsigned short Year, unsigned short Month)
{
	sMonthTimeDuration MonthDuration;

	MonthDuration.Month = Month;

	MonthDuration.Days = NumberOfDaysInAMonth(Year, Month);

	MonthDuration.Hours = NumberOfHoursInAMonth(Year, Month);

	MonthDuration.Minutes = NumberOfMinutesInAMonth(Year, Month);

	MonthDuration.Seconds = NumberOfSecondsInAMonth(Year, Month);

	return MonthDuration;
}

void PrintMonthTimeDuration(const sMonthTimeDuration& Duration)
{
	cout << left << setw(20) << "\nNumber of Days ";
	cout << "in [" << Months[Duration.Month] << "] is " << Duration.Days;

	cout << left << setw(20) << "\nNumber of Hours ";
	cout << "in [" << Months[Duration.Month] << "] is " << Duration.Hours;

	cout << left << setw(20) << "\nNumber of Minutes ";
	cout << "in [" << Months[Duration.Month] << "] is " << Duration.Minutes;

	cout << left << setw(20) << "\nNumber of Seconds ";
	cout << "in [" << Months[Duration.Month] << "] is " << Duration.Seconds;

	cout << endl;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a Month (1-12) : ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

int main()
{
	unsigned short Year, Month;

	Year = ReadYear();
	Month = ReadMonth();

	sMonthTimeDuration Duration = CalculateMonthTimeDuration(Year, Month);

	PrintMonthTimeDuration(Duration);

	system("pause>0");
	return 0;
}