#include <iostream>
using namespace std;

void ReadNumber(unsigned int &Number)
{
	cout << "Please Enter a Number to stop : " << endl;
	cin >> Number;
}

void PrintNumbers(unsigned int Number)
{
	for (unsigned short i = 1; i <= Number; i++)
	{
		cout << i << endl;
	}
}

int main()
{
	unsigned int Number;
	
	ReadNumber(Number);
	PrintNumbers(Number);

	return 0;
}
