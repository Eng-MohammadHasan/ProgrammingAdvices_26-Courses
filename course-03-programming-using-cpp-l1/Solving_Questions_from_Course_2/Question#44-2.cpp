#include <iostream>
using namespace std;

enum enWeekDay { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

void ShowWeekDayMenu()
{
	cout << "***********************\n";
	cout << "       Week Days       \n ";
	cout << "***********************\n";
	cout << "1 : Sunday\n";
	cout << "2 : Monday\n";
	cout << "3 : Tuesday\n";
	cout << "4 : Wednesday\n";
	cout << "5 : Thursday\n";
	cout << "6 : Friday\n";
	cout << "7 : Saturday\n";
	cout << "***********************\n";
	cout << "Please Enter the Number of Day ? " << endl;
}

enWeekDay ReadWeekDay()
{
	enWeekDay WeekDay;

	unsigned short wd;
	cin >> wd;
	WeekDay = (enWeekDay)wd;
	return WeekDay;
}

string GetWeekDayName(enWeekDay WeekDay)
{
	switch (WeekDay)
	{
	case enWeekDay::Sunday:
		return "Sunday";
		break;

	case enWeekDay::Monday:
		return "Monday";
		break;

	case enWeekDay::Tuesday:
		return "Tuesday";
		break;

	case enWeekDay::Wednesday:
		return "Wednesday";
		break;

	case enWeekDay::Thursday:
		return "Thursday";
		break;

	case enWeekDay::Friday:
		return "Friday";
		break;

	case enWeekDay::Saturday:
		return "Saturday";
		break;

	default:
		return "Not a week day!\n";
	}
}


int main()
{
	ShowWeekDayMenu();
	cout << "today is : " << GetWeekDayName(ReadWeekDay()) << endl;

	return 0;
}
