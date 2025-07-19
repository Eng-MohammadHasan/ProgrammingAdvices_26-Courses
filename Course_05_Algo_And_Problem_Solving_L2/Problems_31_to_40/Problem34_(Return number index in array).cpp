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
		arr[i] = RandomNumber(1, 100);
	}
}

int ReadNumber()
{
	int Number = 0;

	cout << "Please Enter a number you search for : " << endl;
	cin >> Number;

	return Number;
}

short FindNumberPositionInArray(int arr[100], int arrayLength, int Number)
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

void SearchResults(int arr[100], int arrayLength, int Number)
{
	short index;
	index = FindNumberPositionInArray(arr, arrayLength, Number);

	if (index == -1)
	{
		cout << "Number you're looking for is : " << Number << endl;
		cout << "The Number isn't found :-( " << endl;
	}
	else
	{
		cout << "Number you're looking for is : " << Number << endl;
		cout << "The number found at position : " << index << endl;
		cout << "The number found its order : " << (index + 1) << endl;
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
	srand((unsigned)time(NULL));

	int arr[100], arrayLength = 0;

	FillArrayWithRandomNumbers(arr, arrayLength);
	PrintArray(arr, arrayLength);

	int Number = ReadNumber();
	SearchResults(arr, arrayLength, Number);

	return 0;
}
