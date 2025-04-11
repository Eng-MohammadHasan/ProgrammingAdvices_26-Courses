#include <iostream>
using namespace std;

void ReadNumbers(int Numbers[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Please Enter Number " << (i + 1) << " : " << endl;
		cin >> Numbers[i];
	}
}

int CalculateSumNumbers(int Numbers[3])
{
	int Sum = 0;

	for (int i = 0; i < 3; i++)
	{
		Sum += Numbers[i];
	}

	return Sum;
}

void PrintSumNumbers(int Numbers[3])
{
	cout << "\nNumbers Summation = " << CalculateSumNumbers(Numbers) << endl;
}

int main()
{
	int Numbers[3];

	ReadNumbers(Numbers);
	PrintSumNumbers(Numbers);

	return 0;
}
