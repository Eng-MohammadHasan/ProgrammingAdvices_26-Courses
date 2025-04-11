#include <iostream>
using namespace std;

void PrintLetters()
{
	int i = 65;
	while (i <= 90)
	{
		cout << char(i) << endl;
		i++;
	}
}

int main()
{
	PrintLetters();

	return 0;
}
