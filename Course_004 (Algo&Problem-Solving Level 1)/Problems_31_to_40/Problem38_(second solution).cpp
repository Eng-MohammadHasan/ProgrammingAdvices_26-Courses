#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeOrNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

enPrimeOrNotPrime CheckPrime(int Number)
{
	if (Number < 2)
	{
		return enPrimeOrNotPrime::NotPrime;
	}

	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
		{
			return enPrimeOrNotPrime::NotPrime;
		}
	}
	return enPrimeOrNotPrime::Prime;
}

void PrintNumberType(int Number)
{

	switch (CheckPrime(Number))
	{
	case enPrimeOrNotPrime::Prime:
		cout << "The number is Prime \n";
		break;

	case enPrimeOrNotPrime::NotPrime:
		cout << "The number is Not Prime \n";
		break;
	}
}

int main()
{
	PrintNumberType((ReadPositiveNumber("Please Enter a positive number : ")));

	return 0;
}
