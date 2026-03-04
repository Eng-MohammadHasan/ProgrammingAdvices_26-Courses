#include <iostream>
#include <string>

using namespace std;

void ReadMonth(unsigned short& MonthNo)
{
	cout << "Please Enter The Month Number : " << endl;
	cin >> MonthNo;
}

string DisplayMonth(unsigned short MonthNo)
{
	if (MonthNo == 1)
	{
		return "January";
	}
	else if (MonthNo == 2)
	{
		return "February";
	}
	else if (MonthNo == 3)
	{
		return "March";
	}
	else if (MonthNo == 4)
	{
		return "April";
	}
	else if (MonthNo == 5)
	{
		return "May";
	}
	else if (MonthNo == 6)
	{
		return "June";
	}
	else if (MonthNo == 7)
	{
		return "July";
	}
	else if (MonthNo == 8)
	{
		return "August";
	}
	else if (MonthNo == 9)
	{
		return "September";
	}
	else if (MonthNo == 10)
	{
		return "October";
	}
	else if (MonthNo == 11)
	{
		return "November";
	}
	else if (MonthNo == 12)
	{
		return "December";
	}
	else
	{
		return "Wrong Month !";
	}
}
int main()
{
	unsigned short MonthNo;

	ReadMonth(MonthNo);
	cout << "\nIts : " << DisplayMonth(MonthNo) << endl;

	return 0;
}
