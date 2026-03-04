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
	int Summation = 0, Number = 0, Counter = 1;

	do
	{
		Number = ReadNumber("Please enter Number " + to_string(Counter) + " : ");

		if (Number == -99)
		{
			break;
		}

		Summation += Number;
		Counter++;

	} while (Number != -99);

	return Summation;
}


int main()
{
	cout << endl << "Summation Result = " << SumNumbers() << endl;

	return 0;
}
