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
	int randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void SummationOf2Arrays(int arraysLength, int arr[100], int arr2[100], int arrSum[100])
{
	for (int i = 0; i < arraysLength; i++)
	{
		arrSum[i] = arr[i] + arr2[i];
	}
}

void PrintArray(int arr[100], int arrayLength)
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

	int arr[100], arr2[100], arrSum[100];
	int arraysLength = ReadPositiveNumber("How many elements : \n");

	FillArrayWithRandomNumbers(arr, arraysLength);
	FillArrayWithRandomNumbers(arr2, arraysLength);

	SummationOf2Arrays(arraysLength, arr, arr2, arrSum);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arraysLength);

	cout << "\nArray 2 elements : \n";
	PrintArray(arr2, arraysLength);

	cout << "\nSum of array 1 and array 2 elements : \n";
	PrintArray(arrSum, arraysLength);

	return 0;
}
