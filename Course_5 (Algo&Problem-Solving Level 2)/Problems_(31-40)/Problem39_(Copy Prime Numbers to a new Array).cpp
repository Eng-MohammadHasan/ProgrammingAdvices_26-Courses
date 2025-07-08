#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

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

enPrimeOrNot CheckPrime(int Number)
{
	/*if (Number % 2 == 0)
		return (Number == 2) ? enPrimeOrNot::Prime : enPrimeOrNot::NotPrime;

	for (int i = 3; i <= M; i += 2)*/

	int M = sqrt(Number);

	if (Number <= 1)
	{
		return enPrimeOrNot::NotPrime;
	}

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
		{
			return enPrimeOrNot::NotPrime;
		}
	}

	return enPrimeOrNot::Prime;
}

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		// If prime, add it to the destination array using the AddArrayElement function.
		if (CheckPrime(arrSource[i]) == enPrimeOrNot::Prime) {
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
	CopyPrimeNumbers(arr, arr2, arrayLength, arr2Length);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrayLength);


	cout << "\nArray 2 Prime numbers:\n";
	PrintArray(arr2, arr2Length);

	return 0;
}
