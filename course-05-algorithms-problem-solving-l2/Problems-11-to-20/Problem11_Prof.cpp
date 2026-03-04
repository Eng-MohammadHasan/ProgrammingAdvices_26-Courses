#include <iostream>
#include <string>

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

int ReverseNumber(int Number)
{
	int Remainder = 0, Number2 = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Number2 = Number2 * 10 + Remainder;
	}

	return Number2;
}

bool IsPalindrome(int Number)
{
	return Number == ReverseNumber(Number);
}

void PrintResults(int Number)
{
	if (IsPalindrome(Number))
	{
		cout << "\nYes , it is a Palindrome number.\n";
	}
	else
	{
		cout << "\nNo , it is NOT a Palindrome number.\n";
	}
}

int main()
{
	PrintResults(ReadPositiveNumber("Please enter a positive number : "));
	return 0;
}
