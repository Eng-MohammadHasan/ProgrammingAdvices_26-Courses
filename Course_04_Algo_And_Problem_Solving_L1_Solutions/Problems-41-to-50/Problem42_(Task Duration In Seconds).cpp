#include <iostream>
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

strTaskDuration ReadTaskDuration()
{
	strTaskDuration TaskDuration;

	TaskDuration.NumberOfDays = ReadPositiveNumber("Please Enter Number of Days : ");
	TaskDuration.NumberOfHours = ReadPositiveNumber("Please Enter Number of Hours : ");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please Enter Number of Minutes : ");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please Enter Number of Seconds : ");

	return TaskDuration;
}

int TaskDurationInSeconds(strTaskDuration TaskDuration)
{
	/*int DaysToSeconds = 24 * 60 * 60;
	int HoursToSeconds = 60 * 60;
	int MinutesToSeconds = 60;*/

	int DurationInSeconds = 0;

	DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;


	return DurationInSeconds;
}


int main()
{


	cout << "\nTask Duration in seconds = " << TaskDurationInSeconds(ReadTaskDuration()) << " Seconds ";
	cout << endl;

	return 0;

}
