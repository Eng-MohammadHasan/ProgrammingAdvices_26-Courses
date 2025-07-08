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

int CountDigitFrequency(int Number, short DigitToCheck)
{

	if (Number == 0 && DigitToCheck == 0)
	{
		return 1;
	}

	int Remainder = 0, FreqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		if (Remainder == DigitToCheck)
		{
			FreqCount++;
		}
	}

	return FreqCount;
}

void PrintAllDigitsFrequency(int Number)
{
	cout << endl;


	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = 0;
		DigitFrequency = CountDigitFrequency(Number, i);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is "
				<< DigitFrequency << " Time(s).\n";
		}
	}
}

int main()
{

	int Number = ReadPositiveNumber("Please enter a number : ");
	PrintAllDigitsFrequency(Number);

	return 0;
}