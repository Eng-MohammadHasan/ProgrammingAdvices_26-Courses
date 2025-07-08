#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number = 0;

	cout << "\nPlease enter a number :";
	cin >> Number;

	return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrayLength)
{
	//it's a new element so we want to add the length by 1
	arrayLength++;
	arr[arrayLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& arrayLength)
{
	bool AddMore = true;

	do
	{
		AddArrayElement(ReadNumber(), arr, arrayLength);

		cout << "\nDo you want to add more numbers? [0]:No , [1]:Yes ? ";
		cin >> AddMore;

	} while (AddMore);
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
	int arr[100], arrayLength = 0;

	InputUserNumbersInArray(arr, arrayLength);

	cout << "\nArray Length : " << arrayLength << endl;

	cout << "Array elements : ";
	PrintArray(arr, arrayLength);

	return 0;
}