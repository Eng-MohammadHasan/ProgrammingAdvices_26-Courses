#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrayLength)
{
	arrayLength = 6;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}

void PrintArray(int arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		arrDestination[i] = arrSource[arrayLength - i - 1];
	}
}

bool IsPalindromeArray(int arrSource[100], int arrDestination[100], int arrayLength)
{
	CopyArrayInReverseOrder(arrSource, arrDestination, arrayLength);

	for (int i = 0; i < arrayLength; i++)
	{
		if (arrSource[i] != arrDestination[i])
		{
			return false;
		}
	}

	return true;
}


int main()
{
	int arr[100], reversedArray[100], arrayLength = 0;
	FillArray(arr, arrayLength);

	cout << "Array Elements :\n";
	PrintArray(arr, arrayLength);

	if (IsPalindromeArray(arr, reversedArray, arrayLength))
	{
		cout << "Yes, array is Palindrome :-)\n";
	}
	else
	{
		cout << "No, array isn't Palindrome :-(\n";
	}

	return 0;
}
