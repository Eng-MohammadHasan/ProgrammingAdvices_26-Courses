#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(short arr[3][3], short Rows, short Columns)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

int RowSum(short arr[3][3], short RowNumber, short Columns)
{
	int Summation = 0;
	for (short j = 0; j <= Columns - 1; j++)
	{
		Summation += arr[RowNumber][j];
	}

	return Summation;
}

void PrintEachRowSum(short arr[3][3], short Rows, short Columns)
{
	cout << "\nThe following are the sum of each row in the matrix: \n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Columns) << endl;
	}
}

void PrintMatrix(short arr[3][3], short Rows, short Columns)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	short arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	PrintEachRowSum(arr, 3, 3);

	system("pause>0");
}
