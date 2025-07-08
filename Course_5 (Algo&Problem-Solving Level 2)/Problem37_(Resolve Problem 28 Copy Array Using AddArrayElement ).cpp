#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int randomNum = rand() % (To - From + 1) + From;
	return randomNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrayLength)
{
	cout << "\nEnter number of elements : \n";
	cin >> arrayLength;

	for (int i = 0; i < arrayLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void AddArrayElement(int Number, int arr[100], int& arrayLength)
{
	arrayLength++;
	arr[arrayLength - 1] = Number;
}

void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrayLength, int& arrLengthDestination)
{
	for (int i = 0; i < arrayLength; i++)
	{
		AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);
	}
}

void PrintArray(int arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main()
{
	// Seeds the random number generator in C++ , called only once
	srand((unsigned)time(NULL));

	int arr[100], arrayLength = 0;

	FillArrayWithRandomNumbers(arr, arrayLength);

	int arr2[100], arr2Length = 0;
	CopyArrayUsingAddArrayElement(arr, arr2, arrayLength, arr2Length);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrayLength);


	cout << "\nArray 2 elements after copy :\n";
	PrintArray(arr2, arr2Length);

	return 0;
}
