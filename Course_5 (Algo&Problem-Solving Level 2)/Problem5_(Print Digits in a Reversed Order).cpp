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


void PrintNumberInReversedOrder(int Number)
{
	string Num = to_string(Number);
	int NumLength = Num.length();

	for (int i = NumLength - 1; i >= 0; i--)
	{
		cout << Num[i] << endl;
	}

}

int main()
{
	PrintNumberInReversedOrder(ReadPositiveNumber("Please Enter a positive number :"));

	return 0;
}
