#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter a number : \n";
	cin >> Number;

	return Number;
}

void PrintRangeFrom1ToN_UsingWhile(int N)
{
	int Counter = 0;

	cout << "Range Printed Using While Statement :\n";

	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}
}


void PrintRangeFrom1ToN_UsingDoWhile(int N)
{

	int Counter = 0;

	cout << "Range Printed Using Do..While Statement :\n";

	do
	{
		Counter++;
		cout << Counter << endl;

	} while (Counter < N);

}


void PrintRangeFrom1ToN_UsingFor(int N)
{

	cout << "Range Printed Using For Statement :\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		cout << Counter << endl;
	}
}



int main()
{

	int N = ReadNumber();

	PrintRangeFrom1ToN_UsingWhile(N);
	PrintRangeFrom1ToN_UsingDoWhile(N);
	PrintRangeFrom1ToN_UsingFor(N);

	return 0;
}
