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
		arr[i] = RandomNumber(-100, 100);
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

short NegativeNumbersCount(int arr[100], int arrayLength)
{
	short Counter = 0;

	for (int i = 0; i < arrayLength; i++)
	{
		if (arr[i] < 0)
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrayLength = 0;
	FillArrayWithRandomNumbers(arr, arrayLength);

	cout << "\nArray Elements :";
	PrintArray(arr, arrayLength);

	cout << "\nNegative Numbers count is : ";
	cout << NegativeNumbersCount(arr, arrayLength) << endl;

	return 0;
}