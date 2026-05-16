#include <iostream>

using namespace std;

enum enDaysOfWeek
{
	Sun = 0,
	Mon = 1,
	Tue = 2,
	Wed = 3,
	Thu = 4,
	Fri = 5,
	Sat = 6
};

unsigned short DayOfWeekOrder(unsigned short Day, unsigned short Month, unsigned short Year)
{
	unsigned short a, y, m, d;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sun , 1:Mon , 2:Tue...etc

	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayName(enDaysOfWeek DayOrder)
{
	switch (DayOrder)
	{
	case enDaysOfWeek::Sun:
		return "Sun";

	case enDaysOfWeek::Mon:
		return "Mon";

	case enDaysOfWeek::Tue:
		return "Tue";

	case enDaysOfWeek::Wed:
		return "Wed";

	case enDaysOfWeek::Thu:
		return "Thu";

	case enDaysOfWeek::Fri:
		return "Fri";

	case enDaysOfWeek::Sat:
		return "Sat";
	}
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

	unsigned short DayOrder = DayOfWeekOrder(Day, Month, Year);

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOrder;
	cout << "\nDay Name  : " << DayName((enDaysOfWeek)DayOrder);

	cout << endl;

	system("pause>0");
	return 0;
}