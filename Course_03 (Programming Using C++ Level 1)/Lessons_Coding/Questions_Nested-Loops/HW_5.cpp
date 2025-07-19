#include <iostream>
using namespace std;


int main()
{
	for (int i = 65; i <= 70; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(j) << " ";
		}
		cout << "\n";
	}
	return 0;
}
