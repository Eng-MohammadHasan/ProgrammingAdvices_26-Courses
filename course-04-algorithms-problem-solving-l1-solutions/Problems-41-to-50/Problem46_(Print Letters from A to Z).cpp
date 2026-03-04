#include <iostream>
using namespace std;

void PrintLettersAToZ()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
}

int main()
{
	PrintLettersAToZ();
	return 0;
}