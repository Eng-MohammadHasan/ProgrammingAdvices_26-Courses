#include <iostream>
using namespace std;

struct sDate
{
	unsigned short Day;
	unsigned short Month;
	unsigned short Year;
};

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

	const unsigned short DaysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
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

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "Please enter a Year: ";
	cin >> Year;

	return Year;
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
	cout << "\nPlease Enter Date 1 ...\n";
	sDate Date1 = ReadFullDate();

	cout << "\n\nPlease Enter Date 2 ...\n";
	sDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2.\n";
	else
		cout << "\nNo, Date1 is NOT Less than Date2.\n";

	system("pause>0");
	return 0;
}
