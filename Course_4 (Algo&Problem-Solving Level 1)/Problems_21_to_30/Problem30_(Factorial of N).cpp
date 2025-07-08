#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do {
		cout << Message;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int FactorialOfN(int Number)
{
	int F = 1;

	for (int Counter = Number; Counter >= 1; Counter--)
	{
		F *= Counter;
	}

	return F;
}


int main()
{
	cout << FactorialOfN(ReadPositiveNumber("Please Enter a positive number ?")) << endl;;

	return 0;
}
