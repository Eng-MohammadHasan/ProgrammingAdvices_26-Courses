#include <iostream>
using namespace std;


unsigned int CalculateNumberOfDays(unsigned int TotalEnteredSeconds, unsigned int secondsPerDay)
{
	unsigned int NumberOfDays;

	NumberOfDays = TotalEnteredSeconds / secondsPerDay;
	return NumberOfDays;
}

unsigned int CalculateNumberOfHours(unsigned int RemainderAfterCuttingDays, unsigned int secondsPerHour)
{
	unsigned int NumberOfHours;

	NumberOfHours = RemainderAfterCuttingDays / secondsPerHour;
	return NumberOfHours;
}

unsigned int CalculateNumberOfMinutes(unsigned int RemainderAfterCuttingHours, unsigned int secondsPerMinute)
{
	unsigned int NumberOfMinutes;

	NumberOfMinutes = RemainderAfterCuttingHours / secondsPerMinute;
	return NumberOfMinutes;
}

unsigned int CalculatingRemainder(unsigned int CertainTimeValue, unsigned int TimeSegmentPerDay)
{
	unsigned int RemainderTime;

	RemainderTime = CertainTimeValue % TimeSegmentPerDay;
	return RemainderTime;
}

unsigned int SecondsPerDay()
{
	return (60 * 60 * 24);
}

unsigned int SecondsPerHour()
{
	return (60 * 60);
}

unsigned int SecondsPerMinute()
{
	return 60;
}

int main()
{
	unsigned int TotalSeconds, NumberOfDays, NumberOfHours, NumberOfMinutes, RemainNumberOfSeconds, Remainder;

	cout << "Please Enter the total number of Seconds : " << endl;
	cin >> TotalSeconds;

	// Number of Days...
	NumberOfDays = CalculateNumberOfDays(TotalSeconds, SecondsPerDay());
	Remainder = CalculatingRemainder(TotalSeconds, SecondsPerDay());


	// Number of Hours...
	NumberOfHours = CalculateNumberOfHours(Remainder, SecondsPerHour());
	Remainder = CalculatingRemainder(Remainder, SecondsPerHour());

	// Number of Minutes...
	NumberOfMinutes = CalculateNumberOfMinutes(Remainder, SecondsPerMinute());
	Remainder = CalculatingRemainder(Remainder, SecondsPerMinute());

	// Number of Seconds...

	RemainNumberOfSeconds = Remainder;

	cout << NumberOfDays << " : " << NumberOfHours << " : " << NumberOfMinutes << " : " << RemainNumberOfSeconds << endl;
	cout << "zaza";
	return 0;
}