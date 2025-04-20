#include <iostream>

using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;

	cout << "Please Enter a number : \n";
	cin >> Number;

	return Number;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 != 0)
	{
		return enOddOrEven::Odd;
	}
	else
	{
		return enOddOrEven::Even;
	}
}

int SumEvenNumbersFrom1ToN_UsingWhile(int N)
{
	int Counter = 0;
	int Sum = 0;

	cout << "Sum even numbers using While Statement:\n";

	while (Counter < N)
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingDoWhile(int N)
{
	int Counter = 0;
	int Sum = 0;

	cout << "Sum even numbers using Do..While Statement:\n";

	do
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	} while (Counter < N);

	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingFor(int N)
{
	int Sum = 0;

	cout << "Sum even numbers using For Statement:\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	}

	return Sum;
}


int main()
{
	int N = ReadNumber();

	cout << SumEvenNumbersFrom1ToN_UsingFor(N) << endl;
	cout << SumEvenNumbersFrom1ToN_UsingWhile(N) << endl;
	cout << SumEvenNumbersFrom1ToN_UsingDoWhile(N) << endl;


	return 0;
}