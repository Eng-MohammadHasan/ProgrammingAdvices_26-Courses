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
	} while (Number <= 0);

	return Number;
}

void ReadArrayElements(int Elements[100], int NumberOfElements)
{
	cout << "Enter Array Elements : \n";

	for (int i = 0; i < NumberOfElements; i++)
	{
		cout << "Element [" << (i + 1) << "] : ";
		cin >> Elements[i];
	}
}

void PrintAllArrayElements(int Elements[100], int NumberOfElements)
{
	for (int i = 0; i < NumberOfElements; i++)
	{
		cout << Elements[i];
	}
	cout << "\n";
}

int CheckNumberRepetition(int Elements[100], int NumberOfElements, int NumberToCheck)
{
	int Counter = 0;

	for (int i = 0; i < NumberOfElements; i++)
	{
		if (Elements[i] == NumberToCheck)
		{
			Counter++;
		}
	}

	return Counter;
}


int main()
{

	int Elements[100], NumberOfElements, NumberToCheck, NumberOfRepetitions;

	NumberOfElements = ReadPositiveNumber("Please Enter Number Of Elements in array : ");
	ReadArrayElements(Elements, NumberOfElements);

	cout << "Original Array : ";
	PrintAllArrayElements(Elements, NumberOfElements);

	cout << endl;
	NumberToCheck = ReadPositiveNumber("Please enter the number you want to check : ");
	NumberOfRepetitions = CheckNumberRepetition(Elements, NumberOfElements, NumberToCheck);

	cout << endl << NumberToCheck << " is repeated " << NumberOfRepetitions << " time(s)" << endl;

	return 0;
}
