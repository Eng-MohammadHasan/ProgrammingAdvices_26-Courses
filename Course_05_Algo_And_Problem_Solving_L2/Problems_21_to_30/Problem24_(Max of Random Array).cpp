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

int MaxNumberInArray(int arr[100], int arrayLength)
{
	int MaxNumber = arr[0];

	for (short i = 1; i < arrayLength; i++)
	{
		if (arr[i] > MaxNumber)
		{
			MaxNumber = arr[i];
		}
	}

	return MaxNumber;
}


int main()
{
	//Seeds the random generator in C++ , called only once 
	srand((unsigned)time(NULL));

	int arr[100], arrayLength;

	FillArrayWithRandomNumbers(arr, arrayLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrayLength);

	cout << "\nMax number is : ";
	cout << MaxNumberInArray(arr, arrayLength) << endl;

	return 0;
}
