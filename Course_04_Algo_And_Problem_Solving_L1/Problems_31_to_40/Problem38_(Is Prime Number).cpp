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

	} while (Number < 0);

	return Number;
}

enPrimeOrNotPrime IsPrime(int Number)
{
	if (Number < 2)
	{
		return enPrimeOrNotPrime::NotPrime;
	}

	for (int i = 2; i <= sqrt(Number); i++)
	{
		if (Number % i == 0)
		{
			return enPrimeOrNotPrime::NotPrime;
		}
	}
	return enPrimeOrNotPrime::Prime;
}

void PrintNumberType(enPrimeOrNotPrime IsPrime)
{
	if (IsPrime == enPrimeOrNotPrime::Prime)
	{
		cout << endl << "The number is Prime " << endl;
	}
	else
	{
		cout << endl << "The number is Not Prime " << endl;
	}

}

int main()
{
	PrintNumberType(IsPrime(ReadPositiveNumber("Please Enter a positive number : ")));

	return 0;
}
