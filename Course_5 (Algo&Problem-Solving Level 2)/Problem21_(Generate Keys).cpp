#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void GenerateKey()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << char(RandomNumber(65, 90));
		}

		if (i == 4)
			break;

		cout << char(45);
	}
	cout << "\n";
}

void PrintGeneratedKeys(int NumberOfKeys)
{
	cout << "\n";

	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : ";
		GenerateKey();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int NumberOfKeys = ReadPositiveNumber("Please Enter number of keys : ");
	PrintGeneratedKeys(NumberOfKeys);
	return 0;
}