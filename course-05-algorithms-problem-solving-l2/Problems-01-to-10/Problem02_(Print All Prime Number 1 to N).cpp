#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrim { Prime = 1, NotPrime = 2 };


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

enPrimeNotPrim IsPrime(int Number)
{
	if (Number < 2)
	{
		return enPrimeNotPrim::NotPrime;
	}

	for (int i = 2; i <= sqrt(Number); i++)
	{
		if (Number % i == 0)
		{
			return enPrimeNotPrim::NotPrime;
		}
	}

	return enPrimeNotPrim::Prime;
}

void PrintNumberType(int Number)
{
	if (IsPrime(Number) == enPrimeNotPrim::Prime)
	{
		cout << "Number [" << Number << "] is Prime." << endl;
	}
	else
	{
		cout << "Number [" << Number << "] is Not Prime :(" << endl;
	}
}

void CheckPrimeStatus1ToN(int StopNumber)
{
	for (int Counter = 1; Counter <= StopNumber; Counter++)
	{
		PrintNumberType(Counter);
	}
}

int main()
{

	CheckPrimeStatus1ToN(ReadPositiveNumber("Please Enter a number to stop :"));

	return 0;
}
