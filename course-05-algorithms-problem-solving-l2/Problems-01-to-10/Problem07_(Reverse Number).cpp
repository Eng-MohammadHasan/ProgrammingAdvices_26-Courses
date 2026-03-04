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
	int Remainder = 0, ReversedNum = 0, Counter = 0;
	string NumAsString[10], NumS = "";

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;


		NumAsString[Counter] = to_string(Remainder);
		Counter++;
	}

	for (int i = 0; i < Counter; i++)
	{
		NumS += NumAsString[i];
	}

	ReversedNum = stoi(NumS);

	return ReversedNum;
}

int main()
{
	cout << ReverseNumber(ReadPositiveNumber("Please enter a positive number : ")) << endl;
	return 0;
}
