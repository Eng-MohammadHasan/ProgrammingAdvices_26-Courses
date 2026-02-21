#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string message)
{
	int Number;

	cout << message << endl;
	cin >> Number;

	return Number;
}

int SumNumbers()
{
	int Summation = 0;
	int Number = 0;
	int Counter = 1;

	Number = ReadNumber("Please enter Number " + to_string(Counter) + " : ");

	while (Number != -99)
	{
		Summation += Number;
		Counter++;

		Number = ReadNumber("Please enter Number " + to_string(Counter) + " : ");
	}

	return Summation;
}


int main()
{
	cout << endl << "Summation Result = " << SumNumbers() << endl;

	return 0;
}
