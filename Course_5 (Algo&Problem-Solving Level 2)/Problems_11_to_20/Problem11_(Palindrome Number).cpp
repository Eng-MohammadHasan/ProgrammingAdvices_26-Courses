#include <iostream>
#include <string>

using namespace std;

enum enIsPalindrome { Palindrome = 1, NotPalindrome = 2 };

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

enIsPalindrome IsPalindrome(int Number)
{
	if (Number == ReverseNumber(Number))
	{
		return enIsPalindrome::Palindrome;
	}
	else
	{
		return enIsPalindrome::NotPalindrome;
	}
}

void PrintResults(enIsPalindrome IsPalindrome)
{
	if (IsPalindrome == enIsPalindrome::Palindrome)
	{
		cout << "Yes , it is a Palindrome number.\n";
	}
	else
	{
		cout << "No , it is NOT a Palindrome number.\n";
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number :");
	PrintResults(IsPalindrome(Number));

	return 0;
}
