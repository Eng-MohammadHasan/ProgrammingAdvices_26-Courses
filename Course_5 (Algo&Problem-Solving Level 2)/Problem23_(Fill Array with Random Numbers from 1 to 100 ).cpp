#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

short ReadPositiveNumber(string message)
{
	short Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

short RandomNumber(short From, short To)
{
	short randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
}

void FillArrayWithRandomNumbers(short arr[100], short arrayLength)
{
	for (short i = 0; i < arrayLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short arr[100], short arrayLength)
{
	for (short i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}


int main()
{
	//Seeds the random generator in C++ , called only once 
	srand((unsigned)time(NULL));

	short arr[100], arrayLength;

	arrayLength = ReadPositiveNumber("\nPlease enter number of elements you want to fill with : ");
	FillArrayWithRandomNumbers(arr, arrayLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrayLength);

	return 0;
}
