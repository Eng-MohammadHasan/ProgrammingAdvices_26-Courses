#include <iostream>
using namespace std;

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

bool IsPerfectNumber(int Number)
{
	int Sum = 0;

	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}

	return Sum == Number;
	/*if (Sum == Number)
	{
		return true;
	}
	else
	{
		return false;
	}*/
}

void PrintResults(int Number)
{
	if (IsPerfectNumber(Number))
	{
		cout << Number << " Is Perfect Number.\n";
	}
	else
	{
		cout << Number << " Is NOT Perfect Number.\n";
	}
}
int main()
{

	PrintResults(ReadPositiveNumber("Please Enter a positive number : "));
	return 0;
}
