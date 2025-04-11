#include <iostream>
using namespace std;

void ReadPositiveIntNumber(int& PositiveNumber)
{
	cout << "Please Enter a positive number : " << endl;
	cin >> PositiveNumber;

	while (PositiveNumber < 0)
	{
		cout << "Wrong Number! , Please enter a positive Number : \n";
		cin >> PositiveNumber;
	}
}

int Factorial(int PositiveNumber)
{
	int i = PositiveNumber;
	int Fac = 1;

	while (i > 0)
	{
		Fac *= i;
		i--;
	}
	return Fac;
}


int main()
{
	int PositiveNumber;

	ReadPositiveIntNumber(PositiveNumber);
	cout << "Factorial = " << Factorial(PositiveNumber) << endl;

	return 0;
}
