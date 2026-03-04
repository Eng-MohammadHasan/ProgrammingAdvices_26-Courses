#include <iostream>
using namespace std;

void FillArray(int arr[100] , int &arrayLength)
{
	arrayLength = 10;
	//(Hard-coded) :-)
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}

void AddArrayElement(int Number, int arr[100], int& arrayLength)
{
	arrayLength++;
	arr[arrayLength - 1] = Number;
}

bool DistinctNumbers(int Number, int arrDestination[100], int arrDestinationLength)
{
	for (int i = 0; i < arrDestinationLength; i++)
	{
		if (arrDestination[i] == Number)
		{
			return false;
		}
	}

	return true;
}

void CopyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		if (DistinctNumbers(arrSource[i], arrDestination, arrDestinationLength))
		{
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
	int arr[10], arr2[10], arrayLength = 0, arr2Length = 0;

	FillArray(arr,arrayLength);
	
	CopyDistinctNumbers(arr, arr2, arrayLength, arr2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrayLength);

	cout << "\nArray 2 distinct elements : \n";
	PrintArray(arr2, arr2Length);


	return 0;
}
