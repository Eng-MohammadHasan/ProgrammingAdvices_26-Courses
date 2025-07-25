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

void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		if (arrSource[i] % 2 != 0)
		{
			// If odd, add it to the destination array using the AddArrayElement function.
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
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
	CopyOddNumbers(arr, arr2, arrayLength, arr2Length);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrayLength);


	cout << "\nArray 2 Odd numbers:\n";
	PrintArray(arr2, arr2Length);

	return 0;
}
