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

void PrintInvertedNumberPattern(int Number)
{
	cout << "\n";

	for (int i = Number; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}
		cout << "\n";
	}
}

int main()
{

	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number : "));


	return 0;
}