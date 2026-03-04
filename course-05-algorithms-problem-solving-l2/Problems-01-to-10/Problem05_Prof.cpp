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

void PrintDigits(int Number)
{
	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10; // Store last digits number inside remainder :)
		Number /= 10; // (Counter),Remove current last digit , that we already stored inside the remainder , this statement will break the loop after n iterations :)
		cout << Remainder << endl; // Print the extracted digit on a new line.
	}
}


int main()
{
	PrintDigits(ReadPositiveNumber("Please Enter a positive number :"));

	return 0;
}
