#include <iostream>
using namespace std;

void ReadNumber(unsigned int& Number)
{
	cout << "Please Enter a Number to stop :\n";
	cin >> Number;
}

unsigned int SummationOddNumbers(unsigned int Number)
{
	unsigned int Summation = 0;

	for (unsigned int i = 1; i <= Number; i += 2)
	{
		Summation += i;
	}
	return Summation;
}

int main()
{
	unsigned int Number;

	ReadNumber(Number);
	cout << "Summation for odd numbers = " << SummationOddNumbers(Number) << endl;

	return 0;
}