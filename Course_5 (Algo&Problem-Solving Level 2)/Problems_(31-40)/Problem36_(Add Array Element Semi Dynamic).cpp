#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

void FillArrayWithElements(int arr[100], int& arrayLength)
{
	short Choice = 0;

	do
	{
		arr[arrayLength] = ReadPositiveNumber("\nPlease enter a number :\n");
		Choice = ReadPositiveNumber("Do you want to add more numbers? [0]:No, [1]:Yes ?");
		arrayLength++;

	} while (Choice != 0);
}

void PrintArrayDetails(int arr[100], int arrayLength)
{
	cout << "Array Length : " << arrayLength << endl;

	cout << "Array elements : ";
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main()
{
	int arr[100], arrayLength = 0;

	FillArrayWithElements(arr, arrayLength);
	PrintArrayDetails(arr, arrayLength);

	return 0;
}