#include <iostream>
using namespace std;

void ReadIntNumber(int& Number)
{
	cout << "Please Enter a number to stop : " << endl;
	cin >> Number;
}

void PrintNumbers(int Number)
{
	int i = 1;

	while (i <= Number)
	{
		cout << i << endl;
		i++;
	}
}

int main()
{
	int Number;

	ReadIntNumber(Number);
	PrintNumbers(Number);

	return 0;
}
