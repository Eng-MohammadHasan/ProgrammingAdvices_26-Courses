#include <iostream>
using namespace std;

void Print2DArray(int MultiplicationTable[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			/*cout << MultiplicationTable[i][j] << " ";*/
			printf("%0*d ", 2, MultiplicationTable[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	int MultiplicationTable[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MultiplicationTable[i][j] = (i + 1) * (j + 1);
		}
	}

	Print2DArray(MultiplicationTable);

	return 0;
}
