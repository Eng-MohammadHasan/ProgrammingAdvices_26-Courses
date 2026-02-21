#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << '\n';
	}
}

int ColumnSummation(int arr[3][3], short Rows, short ColumnNumber)
{
	int Summation = 0;

	for (short i = 0; i < Rows; i++)
	{
		Summation += arr[i][ColumnNumber];
	}

	return Summation;
}

void SumMatrixColumnsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short j = 0; j < Cols; j++)
	{
		arrSum[j] = ColumnSummation(arr, Rows, j);
	}
}

void PrintColsSumArray(int arrSum[3], short length)
{
	cout << "\nThe following are the sum of each col in the matrix:\n";
	for (short j = 0; j < length; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << arrSum[j] << endl;
	}
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColumnsInArray(arr, arrSum, 3, 3);
	PrintColsSumArray(arrSum, 3);

	system("pause>0");
}
