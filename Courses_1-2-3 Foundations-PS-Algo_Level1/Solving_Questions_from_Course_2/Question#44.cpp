#include <iostream>
using namespace std;

void ReadDay(unsigned short& Day)
{
	cout << "Please Enter The Day Number : \n";
	cin >> Day;
}

string DisplayDay(unsigned short Day)
{
	if (Day == 1)
	{
		return "Sunday";
	}
	else if (Day == 2)
	{
		return "Monday";
	}
	else if (Day == 3)
	{
		return "Tuesday";
	}
	else if (Day == 4)
	{
		return "Wednesday";
	}
	else if (Day == 5)
	{
		return "Thursday";
	}
	else if (Day == 6)
	{
		return "Friday";
	}
	else if (Day == 7)
	{
		return "Saturday";
	}
	else
	{
		return "Wrong Day ! ";
	}
}

int main()
{
	unsigned short Day;

	ReadDay(Day);
	cout << "Its " << DisplayDay(Day) << endl;

	return 0;
}
