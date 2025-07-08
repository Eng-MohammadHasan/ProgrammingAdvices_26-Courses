#include <iostream>
using namespace std;


void ReadNumber(int& PositiveNumber)
{
	cout << "Please Enter a positive number : " << endl;
	cin >> PositiveNumber;
}

 int Factorial( int PositiveNumber)
{
	 int Fac = 1;

	for (unsigned int i = PositiveNumber; i >= 1; i--)
	{
		Fac *= i;
	}

	return Fac;
}


int main()
{
	 int PositiveNumber;

	ReadNumber(PositiveNumber);

	cout << "Factorial for the entered number = " << Factorial(PositiveNumber) << endl;

	return 0;
}
