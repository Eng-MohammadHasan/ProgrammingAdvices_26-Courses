#include <iostream>
#include <cmath>

using namespace std;

int CalculateTaskDurationInSeconds(unsigned Days, unsigned Hours, unsigned Minutes, unsigned Seconds)
{
	return (Days * 24 * 60 * 60) + (Hours * 60 * 60) + (Minutes * 60) + (Seconds));
}

int main()
{
	unsigned int Days, Hours, Minutes, Seconds;

	cout << "Please Enter the time duration of the task in Days : " << endl;
	cin >> Days;

	cout << "Please Enter the time duration of the task in Hours : " << endl;
	cin >> Hours;

	cout << "Please Enter the time duration of the task in Minutes : " << endl;
	cin >> Minutes;

	cout << "Please Enter the time duration of the task in Seconds : " << endl;
	cin >> Seconds;

	cout << "The task duration in seconds = " << CalculateTaskDurationInSeconds(Days, Hours, Minutes, Seconds) << " Seconds !" << endl;
	return 0;
}
