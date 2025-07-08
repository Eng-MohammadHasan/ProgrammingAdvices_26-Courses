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

int StoreReverseNumberInArray(int Number, int NumberDigitsInReverse[10])
{
	int Remainder = 0;
	short Counter = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		NumberDigitsInReverse[Counter] = Remainder;
		Counter++;
	}

	return Counter; // Return how many digits were stored
}

void PrintNumberInOrder(int Counter, int NumberDigitsInReverse[10])
{
	for (int i = Counter - 1; i >= 0; i--)
	{
		cout << NumberDigitsInReverse[i] << endl;
	}
}


int main()
{
	int NumberDigitsInReverse[10];
	int Number = ReadPositiveNumber("Please enter a positive number :");
	int Count = StoreReverseNumberInArray(Number, NumberDigitsInReverse);
	PrintNumberInOrder(Count, NumberDigitsInReverse);

	return 0;
}