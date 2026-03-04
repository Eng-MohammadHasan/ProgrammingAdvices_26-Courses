#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

enum enCharType { CapitalLetter = 1, SmallLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
	}

	return '\0';
}

string GenerateWord(enCharType CharType, int Length)
{
	string word = "";

	for (int i = 0; i < Length; i++)
	{
		word += GetRandomCharacter(CharType);
	}

	return word;
}

string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int NumberOfKeys)
{
	for (int i = 0; i < NumberOfKeys; i++)
	{
		arr[i] = GenerateKey();
	}
}

void PrintStringArray(string arr[100], int arrayLength)
{
	cout << "\nArray elements : \n\n";

	for (int i = 0; i < arrayLength; i++)
	{
		cout << "Array [" << i << "] : ";
		cout << arr[i] << "\n";
	}
	cout << endl;
}

int main()
{

	srand((unsigned)time(NULL));

	string arr[100];
	int arrayLength = 0;

	arrayLength = ReadPositiveNumber("How many Keys do you want to generate :\n	");

	FillArrayWithKeys(arr, arrayLength);
	PrintStringArray(arr, arrayLength);

	return 0;
}
