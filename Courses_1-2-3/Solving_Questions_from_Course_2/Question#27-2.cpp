#include <iostream>
using namespace std;

void ReadIntNumber(int& Number)
{
	cout << "Please Enter a number to start : " << endl;
	cin >> Number;
}

void PrintNumbers(int Number)
{
	int i = Number;

	while (i > 0)
	{
		cout << i << endl;
		i--;
	}
}

int main()
{
	int Number;

	ReadIntNumber(Number);
	PrintNumbers(Number);

	return 0;
}
