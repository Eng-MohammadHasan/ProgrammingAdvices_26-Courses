#include <iostream>
using namespace std;

unsigned int ReadNumber()
{
	unsigned int Number;

	cout << "Please Enter a Number : \n";
	cin >> Number;

	return Number;
}

unsigned int ReadPower()
{
	unsigned int M;

	cout << "Please Enter a Power : \n";
	cin >> M;

	return M;
}

unsigned int PowerOfM(unsigned int Number, unsigned int M)
{
	if (M == 0)
	{
		return 1;
	}

	int Product = 1;

	for (unsigned int i = 1; i <= M; i++)
	{
		Product *= Number;
	}

	return Product;
}

int main()
{
	unsigned int Number = ReadNumber();
	unsigned int Power = ReadPower();

	cout << "Number ^ M = " << PowerOfM(Number, Power) << endl;

	return 0;
}