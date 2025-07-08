#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{
	cout << "Please Enter Number : " << endl;
	cin >> Number;

}

void ReadPower(unsigned int& M)
{
	cout << "Please Enter Power : " << endl;
	cin >> M;
}

int PowerOfM(int Number, unsigned int M)
{
	if (M == 0)
	{
		return 1;
	}

	int i = 1;
	int Product = 1;

	while (i <= M)
	{
		Product *= Number;
		i++;
	}
	return Product;
}

int main()
{

	int Number;
	unsigned int M;

	ReadNumber(Number);
	ReadPower(M);

	cout << "Number ^ M = " << PowerOfM(Number, M) << endl;


	return 0;
}
