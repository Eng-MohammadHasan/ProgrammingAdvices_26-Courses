#include <iostream>
using namespace std;


int main()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << "Letter:" << char(i) << endl;
		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << char(j) << "\n";
		}
		cout << "---------------------\n";
	}
	return 0;
}
