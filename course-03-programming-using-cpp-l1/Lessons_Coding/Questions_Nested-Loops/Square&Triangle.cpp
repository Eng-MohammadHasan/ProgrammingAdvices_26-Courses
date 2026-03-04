#include <iostream>
using namespace std;


int main()
{
	// Question 1 ...
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}


	// Question 2 ...
	cout << "\n\n";
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}
