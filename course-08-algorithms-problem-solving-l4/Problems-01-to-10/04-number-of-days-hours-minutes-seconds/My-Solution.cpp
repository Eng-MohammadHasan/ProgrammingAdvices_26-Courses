#include <iostream>
#include <iomanip>

using namespace std;

const unsigned short HoursInADay = 24;
const unsigned short MinutesInADay = (24 * 60);
const unsigned int SecondsInADay = (24 * 60 * 60);

struct sYearTimeDuration
{
	unsigned short Year;
	unsigned short Days;
	unsigned short Hours;
	unsigned int Minutes;
	unsigned int Seconds;
};

bool isLeapYear(unsigned short Year)
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

unsigned short CountDaysInAYear(unsigned short Year)
{
	return (isLeapYear(Year)) ? 366 : 365;
}

unsigned short CountHoursInAYear(unsigned short Year)
{
	return CountDaysInAYear(Year) * HoursInADay;
}

unsigned int CountMinutesInAYear(unsigned short Year)
{
	return CountDaysInAYear(Year) * MinutesInADay;
}

unsigned int CountSecondsInAYear(unsigned short Year)
{
	return CountDaysInAYear(Year) * SecondsInADay;
}

sYearTimeDuration CalculateYearTimeDuration(unsigned short Year)
{
	sYearTimeDuration YearDuration;

	YearDuration.Year = Year;

	YearDuration.Days = CountDaysInAYear(Year);

	YearDuration.Hours = CountHoursInAYear(Year);

	YearDuration.Minutes = CountMinutesInAYear(Year);

	YearDuration.Seconds = CountSecondsInAYear(Year);

	return YearDuration;
}

void DisplayYearTimeDuration(const sYearTimeDuration& YearDuration)
{
	cout << left << setw(20) << "\nNumber of Days ";
	cout << "in year [" << YearDuration.Year << "] is " << YearDuration.Days;

	cout << left << setw(20) << "\nNumber of Hours ";
	cout << "in year [" << YearDuration.Year << "] is " << YearDuration.Hours;

	cout << left << setw(20) << "\nNumber of Minutes ";
	cout << "in year [" << YearDuration.Year << "] is " << YearDuration.Minutes;

	cout << left << setw(20) << "\nNumber of Seconds ";
	cout << "in year [" << YearDuration.Year << "] is " << YearDuration.Seconds;

	cout << endl;
}

int main()
{
	unsigned short Year;
	Year = ReadYear();

	DisplayYearTimeDuration(CalculateYearTimeDuration(Year));

	system("pause>0");
	return 0;
}
