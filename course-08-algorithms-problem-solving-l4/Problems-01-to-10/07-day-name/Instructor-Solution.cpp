#include <iostream>

using namespace std;

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

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

unsigned short ReadDay()
{
	unsigned short Day;

	cout << "\nPlease enter a day? ";
	cin >> Day;

	return Day;
}

unsigned short ReadMonth()
{
	unsigned short Month;

	do
	{
		cout << "\nPlease enter a month (1 - 12)? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

unsigned short ReadYear()
{
	unsigned short Year;

	cout << "\nPlease enter a year? ";
	cin >> Year;

	return Year;
}

int main()
{
	unsigned short Year, Month, Day;

	Year = ReadYear();
	Month = ReadMonth();
	Day = ReadDay();

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));

	system("pause>0");
	return 0;
}