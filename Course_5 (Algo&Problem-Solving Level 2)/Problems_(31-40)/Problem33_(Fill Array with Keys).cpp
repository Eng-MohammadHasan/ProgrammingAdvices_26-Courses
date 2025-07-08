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
	int randomNum = rand() % (To - From + 1) + From;
	return randomNum;
}

string GenerateWord(int NumberOfLetters)
{
	string word = "";
	for (int i = 0; i < NumberOfLetters; i++)
	{
		word += char(RandomNumber(65, 90));
	}

	return word;
}

string GenerateKey(int NumberOfLetters)
{
	string Key = "";

	Key = GenerateWord(NumberOfLetters) + "-";
	Key += GenerateWord(NumberOfLetters) + "-";
	Key += GenerateWord(NumberOfLetters) + "-";
	Key += GenerateWord(NumberOfLetters);

	return Key;
}

void FillKeysInArray(string arr[100], int NumberOfKeys, int NumberOfLetters)
{
	for (int i = 0; i < NumberOfKeys; i++)
	{
		arr[i] = GenerateKey(NumberOfLetters);
	}
}

void PrintArray(string arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "Array [" << i << "] : " << arr[i] << " ";
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string arr[100];
	int arrayLength = ReadPositiveNumber("Please Enter number of Keys you want to generate : ");

	FillKeysInArray(arr, arrayLength, 4);
	PrintArray(arr, arrayLength);

	return 0;
}