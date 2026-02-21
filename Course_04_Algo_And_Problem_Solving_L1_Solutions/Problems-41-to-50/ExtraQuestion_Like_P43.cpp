#include <iostream>

using namespace std;

struct stTimeSpan
{
	unsigned short Years;
	unsigned short Months;
	unsigned short Days;
};

stTimeSpan CalculateTimeSpanFromDays(unsigned int NumberOfDays)
{
	stTimeSpan TimeSpan;
	unsigned int Remainder = 0;

	const unsigned int DaysPerYear = 365;
	const unsigned int DaysPerMonth = 30;


	TimeSpan.Years = (int)(NumberOfDays / 365);
	Remainder = NumberOfDays % DaysPerYear;

	TimeSpan.Months = (int)(Remainder / 30);
	Remainder = Remainder % DaysPerMonth;

	TimeSpan.Days = Remainder;

	return TimeSpan;
}

void PrintTimeSpan(const stTimeSpan& TimeSpan)
{
	cout << TimeSpan.Years << " years" << endl;
	cout << TimeSpan.Months << " months" << endl;
	cout << TimeSpan.Days << " days" << endl;
}

int main()
{
	unsigned int NumberOfDays;
	cin >> NumberOfDays;

	PrintTimeSpan(CalculateTimeSpanFromDays(NumberOfDays));

	return 0;
}
