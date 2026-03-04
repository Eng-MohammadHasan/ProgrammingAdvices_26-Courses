#include <iostream>
using namespace std;

void ReadIntNumber(unsigned int& Number)
{
	cout << "Please Enter a number to stop : " << endl;
	cin >> Number;
}

unsigned int SummationOddNumbers(unsigned int Number)
{
	int i = 1;
	int Summation = 0;

	while (i <= Number)
	{
		Summation += i;
		i += 2;
	}

	return Summation;
}

int main()
{
	unsigned int Number;

	ReadIntNumber(Number);
	cout << "Summation for odd numbers = " << SummationOddNumbers(Number) << endl;

	return 0;
}
