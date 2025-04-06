#include <iostream>
#include <string>

using namespace std;

enum enMonths { January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };


enMonths ReadMonthNo(unsigned short& MonthNo)
{
	cout << "Please enter a month [1 to 12]:" << endl;
	cin >> MonthNo;

	return (enMonths)MonthNo;

}

string DisplayMonth(unsigned short Month)
{
	switch (Month)
	{

	case enMonths::January:
		return "January";
		break;

	case enMonths::February:
		return "February";
		break;

	case enMonths::March:
		return "March";
		break;

	case enMonths::April:
		return "April";
		break;

	case enMonths::May:
		return "May";
		break;

	case enMonths::June:
		return "June";
		break;

	case enMonths::July:
		return "July";
		break;

	case enMonths::August:
		return "August";
		break;

	case enMonths::September:
		return "September";
		break;

	case enMonths::October:
		return "October";
		break;

	case enMonths::November:
		return "November";
		break;

	case enMonths::December:
		return "December";
		break;

	default:
		return "Not a month !";
	}
}

int main()
{
	unsigned short MonthNo;

	enMonths Month = ReadMonthNo(MonthNo);
	cout << "It's " << DisplayMonth(Month) << endl;

	return 0;
}
