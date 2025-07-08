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

int SumOfDigits(int Number)
{
	int Summation = 0, Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Summation += Remainder;
	}

	return Summation;
}

int main()
{
	cout << "\nSum Of Digits = "
		<< SumOfDigits(ReadPositiveNumber("Please Enter a positive number : "))
		<< "\n";
	return 0;
}
