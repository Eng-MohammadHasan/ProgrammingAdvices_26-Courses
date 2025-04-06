#include <iostream>
using namespace std;

void PrintCapitalLetters()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
	cout << "***************************\n";
}

void PrintSmallLetters()
{
	for (int i = 97; i <= 122; i++)
	{
		cout << char(i) << endl;
	}
}

int main()
{
	PrintCapitalLetters();
	PrintSmallLetters();

	return 0;
}