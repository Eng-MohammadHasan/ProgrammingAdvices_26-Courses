#include <iostream>
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

void ReadArray(int arr[100], int& arrLength)
{
	cout << "\nPlease enter number of elements : \n";
	cin >> arrLength;

	cout << "\nEnter Array Elements : \n";

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << (i + 1) << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int TimesRepeated(int NumberToCheck, int arr[100], int arrLength)
{
	int Count = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == NumberToCheck)
		{
			Count++;
		}
	}

	return Count;
}


int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Please enter the number you want to check : ");

	cout << "\nOriginal Array : ";
	PrintArray(arr, arrLength);

	cout << "\nNumber " << NumberToCheck;
	cout << " is repeated ";
	cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";

	return 0;
}

