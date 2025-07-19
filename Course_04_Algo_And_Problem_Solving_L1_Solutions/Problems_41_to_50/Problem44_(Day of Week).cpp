#include <iostream>
#include <string>

using namespace std;

enum enDayOfWeek { Saturday = 1, Sunday = 2, Monday = 3, Tuesday = 4, Wednesday = 5, Thursday = 6, Friday = 7 };

int ReadNumberInRange(int From, int To, string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number < From || Number >To);

	return Number;
}

enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange(1, 7, "Please enter day number (Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri= 7 ) : ");
}

string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{

	case enDayOfWeek::Saturday:
		return "Saturday";

	case enDayOfWeek::Sunday:
		return "Sunday";

	case enDayOfWeek::Monday:
		return "Monday";

	case enDayOfWeek::Tuesday:
		return "Tuesday";

	case enDayOfWeek::Wednesday:
		return "Wednesday";

	case enDayOfWeek::Thursday:
		return "Thursday";

	case enDayOfWeek::Friday:
		return "Friday";
	default:
		return "Not a valid day!";
	}
}

int main()
{
	cout << endl << GetDayOfWeek(ReadDayOfWeek()) << endl;

	return 0;
}