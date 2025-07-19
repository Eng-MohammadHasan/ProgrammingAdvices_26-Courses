#include <iostream>
#include <string>

using namespace std;

float ReadNumbers(string Message)
{
	float Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

float SumNumbers()
{
	float Number;
	float Summation = 0;
	int Counter = 1;

	Number = ReadNumbers("Please Enter Number " + to_string(Counter) + " : " + "(Or - 99 to exit...) ");

	while (Number != -99)
	{
		Summation += Number;
		Counter++;

		Number = ReadNumbers("Please Enter Number " + to_string(Counter) + " : " + "(Or - 99 to exit...) ");

	}
	return Summation;
}

int main()
{
	cout << endl << "Result = " << SumNumbers() << endl;

	return 0;
}
