#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << '\t';
		}
		cout << '\n';
	}
}

void FillRow(int arr[3][3], int arr2[3][3], short ColNumber, short Rows)
{
	for (short i = 0; i < Rows; i++)
	{
		arr2[i][ColNumber] = arr[ColNumber][i];
	}
}

void TransposeMatrix(int arr[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		FillRow(arr, arr2, i, Rows);
	}
}

int main()
{
	int arr[3][3];
	int arr2[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	TransposeMatrix(arr, arr2, 3, 3);

	cout << "\nThe following is transposed matrix:\n";
	PrintMatrix(arr2, 3, 3);

	system("pause>0");
}
