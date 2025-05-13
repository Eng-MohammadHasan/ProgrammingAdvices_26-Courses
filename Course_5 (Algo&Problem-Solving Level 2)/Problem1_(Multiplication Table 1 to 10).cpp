#include <iostream>
using namespace std;

void PrintTableHeader()
{
	cout << "\t\t\t\tMultiplication Table From 1 to 10\n";
	cout << "\t\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl << "_______________________________________________________________________________________________" << endl;
}

void PrintMultiplicationTable1To10()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t|\t";
		for (int j = 1; j <= 10; j++)

		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}

int main()
{
	PrintTableHeader();
	PrintMultiplicationTable1To10();


	return 0;
}
