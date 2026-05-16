#include <iostream>
#include <iomanip>

using namespace std;

const unsigned short HoursInADay = 24;
const unsigned short MinutesInAnHour = 60;
const unsigned short SecondsInAMinute = 60;

struct sYearTimeDuration
{
	unsigned short Year;
	unsigned short Days;
	unsigned short Hours;
	unsigned int Minutes;
	unsigned int Seconds;
};

bool IsLeapYear(unsigned short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if years is divisble by 400 
	// then it is a leap year
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

unsigned short NumberOfDaysInAYear(unsigned short Year)
{
	return (IsLeapYear(Year)) ? 366 : 365;
}

unsigned short NumberOfHoursInAYear(unsigned short Year)
{
	return NumberOfDaysInAYear(Year) * HoursInADay;
}

unsigned int NumberOfMinutesInAYear(unsigned short Year)
{
	return NumberOfHoursInAYear(Year) * MinutesInAnHour;
}

unsigned int NumberOfSecondsInAYear(unsigned short Year)
{
	return NumberOfMinutesInAYear(Year) * SecondsInAMinute;
}

sYearTimeDuration CalculateYearTimeDuration(unsigned short Year)
{
	sYearTimeDuration YearDuration;

	YearDuration.Year = Year;

	YearDuration.Days = NumberOfDaysInAYear(Year);

	YearDuration.Hours = NumberOfHoursInAYear(Year);

	YearDuration.Minutes = NumberOfMinutesInAYear(Year);

	YearDuration.Seconds = NumberOfSecondsInAYear(Year);

	return YearDuration;
}

void PrintYearTimeDuration(const sYearTimeDuration& Duration)
{
	cout << left << setw(20) << "\nDays"
		<< ": " << Duration.Days;

	cout << left << setw(20) << "\nHours"
		<< ": " << Duration.Hours;

	cout << left << setw(20) << "\nMinutes"
		<< ": " << Duration.Minutes;

	cout << left << setw(20) << "\nSeconds"
		<< ": " << Duration.Seconds;

	cout << endl;
}

int main()
{
	unsigned short Year;
	Year = ReadYear();

	sYearTimeDuration Duration = CalculateYearTimeDuration(Year);

	PrintYearTimeDuration(Duration);

	system("pause>0");
	return 0;
}
