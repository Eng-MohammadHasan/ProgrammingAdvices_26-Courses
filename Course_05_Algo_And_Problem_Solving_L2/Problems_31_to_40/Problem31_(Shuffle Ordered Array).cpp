#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
}

void FillArrayWith1ToN(int arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		arr[i] = i + 1;
	}
}

void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void ShuffleArray(int arr[100], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		int index1 = RandomNumber(1, arrayLength) - 1;
		int index2 = RandomNumber(1, arrayLength) - 1;

		Swap(arr[index1], arr[index2]);
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

int main()
{

	//Seeds the random generator in C++ , called only once 
	srand((unsigned)time(NULL));


	int arr[100];
	int arrayLength = ReadPositiveNumber("\nPlease enter a number : \n");

	FillArrayWith1ToN(arr, arrayLength);

	cout << "\nArray elements before shuffle : \n";
	PrintArray(arr, arrayLength);

	ShuffleArray(arr, arrayLength);

	cout << "\nArray elements after shuffle : \n";
	PrintArray(arr, arrayLength);

	return 0;
}