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

	cout << "\nPlease Enter a number you search for : " << endl;
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
	// if your reached here , this means the number isn't found  
	return -1;
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
	//seeds the random generator in c++ , called only 
	srand((unsigned)time(NULL));

	int arr[100], arrayLength = 0;
	FillArrayWithRandomNumbers(arr, arrayLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrayLength);

	int Number = ReadNumber();
	cout << "\nNumber you're looking for is :" << Number << endl;

	short NumberPosition = FindNumberPositionInArray(arr, arrayLength, Number);

	if (NumberPosition == -1)
	{
		cout << "The Number isn't found :-(\n";
	}
	else
	{
		cout << "The Number found at position : " << NumberPosition << endl;
		cout << "The Number found its order : " << NumberPosition + 1 << endl;
	}

	return 0;
}
