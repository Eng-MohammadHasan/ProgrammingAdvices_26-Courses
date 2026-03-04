#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number)
{
	if (Number < 2)
	{
		return enPrimeNotPrime::NotPrime;
	}

	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}

	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Prime Number from " << 1 << " To " << Number;
	cout << " are : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{

	PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? "));

	return 0;
}
