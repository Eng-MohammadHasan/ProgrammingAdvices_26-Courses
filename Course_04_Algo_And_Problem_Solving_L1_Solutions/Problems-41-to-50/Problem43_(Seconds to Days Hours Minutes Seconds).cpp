#include <iostream>
#include <cmath>

using namespace std;

struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

strTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	strTaskDuration TaskDuration;

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;


	int Remainder = 0;
	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
	Remainder = TotalSeconds % SecondsPerDay;

	TaskDuration.NumberOfHours = floor(Remainder / SecondsPerHour);
	Remainder %= SecondsPerHour;

	TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinute);
	Remainder %= SecondsPerMinute;

	TaskDuration.NumberOfSeconds = Remainder;

	return TaskDuration;
}

void PrintTaskDurationDetails(strTaskDuration TaskDuration)
{
	cout << "\n";

	cout << TaskDuration.NumberOfDays << " : "
		<< TaskDuration.NumberOfHours << " : "
		<< TaskDuration.NumberOfMinutes << " : "
		<< TaskDuration.NumberOfSeconds << "\n";
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("Please Enter Total number of seconds : ");
	PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));
	return 0;
}
