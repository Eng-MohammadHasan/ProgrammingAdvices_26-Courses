#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
	int randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
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

void PrintArray(int arr[100], int arrayLength)
{
	for (short i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		arrDestination[i] = arrSource[i];
	}
}

int main()
{
	//Seeds the random generator in C++ , called only once 
	srand((unsigned)time(NULL));

	int arr[100], arrayLength;

	FillArrayWithRandomNumbers(arr, arrayLength);

	int arr2[100];

	CopyArray(arr, arr2, arrayLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrayLength);

	cout << "\nArray 2 elements after copy : \n";
	PrintArray(arr2, arrayLength);

	return 0;
}
