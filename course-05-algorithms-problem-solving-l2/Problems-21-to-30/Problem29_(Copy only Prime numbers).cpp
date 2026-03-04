#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

enum enPrimeOrNotPrime { Prime = 1, NotPrime = 2 };

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

bool PrimeNumbers(int Number)
{
	if (Number == 1)
	{
		return false;
	}

	for (int i = 2; i <= sqrt(Number); i++)
	{
		if (Number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& array2Length)
{
	for (int i = 0; i < arrayLength; i++)
	{
		if (PrimeNumbers(arrSource[i]))
		{
			arrDestination[array2Length] = arrSource[i];
			array2Length++;
		}
	}
}

int main()
{

	//Seeds the random generator in C++ , called only once 
	srand((unsigned)time(NULL));

	int arr[100], arrayLength;

	FillArrayWithRandomNumbers(arr, arrayLength);

	int arr2[100], array2Length = 0;

	CopyPrimeNumbers(arr, arr2, arrayLength, array2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrayLength);

	cout << "\nArray 2 elements after copying Prime Numbers : \n";
	PrintArray(arr2, array2Length);

	return 0;
}
