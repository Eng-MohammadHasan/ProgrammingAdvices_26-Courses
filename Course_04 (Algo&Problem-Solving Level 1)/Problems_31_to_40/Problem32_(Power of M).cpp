#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber(string message)
{
	int Number;

	cout << message << endl;
	cin >> Number;

	return Number;
}

int PowerOfM(int Number, int M)
{
	int Result = pow(Number, M);

	return Result;
}

void PrintResult(int Result)
{
	cout << "Result = " << Result << endl;
}
int main()
{
	int Number = ReadNumber("Please Enter a Number : ");
	int Power = ReadNumber("Please Enter a Power : ");

	PrintResult(PowerOfM(Number, Power));

	return 0;
}
