#include <iostream>
#include <string>
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

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		arrDestination[i] = arrSource[arrayLength - 1 - i];
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
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr1[100], arrayLength;

	FillArrayWithRandomNumbers(arr1, arrayLength);

	int arr2[100];
	CopyArrayInReverseOrder(arr1, arr2, arrayLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr1, arrayLength);

	cout << "\nArray 2 elements after copying array : \n";
	PrintArray(arr2, arrayLength);

	return 0;
}