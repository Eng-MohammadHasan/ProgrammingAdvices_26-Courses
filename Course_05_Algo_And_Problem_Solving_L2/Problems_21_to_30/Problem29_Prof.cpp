#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

enum enPrimeOrNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeOrNotPrime CheckPrime(int Number)
{
	if (Number == 1)
	{
		return enPrimeOrNotPrime::NotPrime;
	}

	for (int i = 2; i <= sqrt(Number); i++)
	{
		if (Number % i == 0)
		{
			return enPrimeOrNotPrime::NotPrime;
		}
	}

	return enPrimeOrNotPrime::Prime;
}

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& array2Length)
{
	int Counter = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeOrNotPrime::Prime)
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}
	}

	array2Length = Counter;
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

	int arr[100], arrayLength;

	FillArrayWithRandomNumbers(arr, arrayLength);

	int arr2[100], array2Length = 0;
	CopyOnlyPrimeNumbers(arr, arr2, arrayLength, array2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrayLength);

	cout << "\nPrime Numbers in array 2 : \n";
	PrintArray(arr2, array2Length);

	return 0;
}
