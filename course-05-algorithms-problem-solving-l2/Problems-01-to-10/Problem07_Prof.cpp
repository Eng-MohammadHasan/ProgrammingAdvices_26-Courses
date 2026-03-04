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
		Number2 = Number2 * 10 + Remainder; // Shift left :)
	}
	return Number2;
}

int main()
{
	cout << "\nReverse is :\n"
		<< ReverseNumber(ReadPositiveNumber("Please enter a positive number?"))
		<< "\n";
	return 0;
}