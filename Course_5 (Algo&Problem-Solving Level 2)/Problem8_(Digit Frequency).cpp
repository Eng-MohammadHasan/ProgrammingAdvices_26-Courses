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

int main()
{
	int Number = ReadPositiveNumber("Please enter the main number : ");
	short DigitToCheck = ReadPositiveNumber("Please enter one digit to check : ");

	cout << "\nDigit " << DigitToCheck << " Frequency is "
		<< CountDigitFrequency(Number, DigitToCheck) << " Time(s)\n";

	return 0;
}
