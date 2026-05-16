#include <iostream>
using namespace std;

bool isLeapYear(unsigned short Year)
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

	static const unsigned short DaysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

unsigned short NumberOfDaysFromStartOfYear(unsigned short Day, unsigned short Month, unsigned short Year)
{
	unsigned short TotalDays = 0;

	for (int i = 1; i < Month ; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	return TotalDays + Day;
}

// ---------- INPUT ----------

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a Month (1-12): ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a Year: ";
	cin >> Year;

	return Year;
}

unsigned short ReadDay(unsigned short Month , unsigned short Year)
{
	unsigned short Day;
	unsigned short MaximumDays = NumberOfDaysInAMonth(Month, Year);

	do
	{
		cout << "\nPlease enter Day (1 - " << MaximumDays << "): ";
		cin >> Day;

	} while (Day < 1 || Day > MaximumDays);
	
	return Day;
}

int main()
{
	unsigned short Month = ReadMonth();
	unsigned short Year = ReadYear();
	unsigned short Day = ReadDay(Month , Year);

	cout << "\nNumber of Days from the beginning of the year is : "
		<< NumberOfDaysFromStartOfYear(Day, Month, Year) << endl << endl;

	return 0;
}