#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrayLength)
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

short FindNumberPositionInArray(int Number, int arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		if (arr[i] == Number)
		{
			return i;
		}
	}

	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrayLength)
{
	return FindNumberPositionInArray(Number, arr, arrayLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int& arrayLength)
{
	arrayLength++;
	arr[arrayLength - 1] = Number;
}

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
	for (int i = 0; i < SourceLength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
		{
			AddArrayElement(arrSource[i], arrDestination, DestinationLength);
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
	int arrSource[10], SourceLength = 0, arrDestination[100], DestinationLength = 0;
	FillArray(arrSource, SourceLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arrSource, SourceLength);

	CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);

	cout << "\nArray 2 distinct elements :\n";
	PrintArray(arrDestination, DestinationLength);


	return 0;
}
