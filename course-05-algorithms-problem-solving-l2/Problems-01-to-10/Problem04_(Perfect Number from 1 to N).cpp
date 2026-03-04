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
}

void PrintPerfectNumbersFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Perfect Numbers from " << 1 << " To " << Number;
	cout << " are : \n\n";

	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << " Is a Perfect Number.\n";
		}
	}
}
int main()
{

	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please Enter a positive number : "));
	return 0;
}
