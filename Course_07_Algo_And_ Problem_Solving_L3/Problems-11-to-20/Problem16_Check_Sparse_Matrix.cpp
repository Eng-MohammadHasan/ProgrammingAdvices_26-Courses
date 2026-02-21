#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				NumberCount++;
			}
		}
	}

	return NumberCount;
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

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;
	return (CountNumberInMatrix(Matrix1, 0, Rows, Cols) >= ceil((float)MatrixSize / 2));
}

int main()
{
	//int Matrix1[3][3] = { {9,1,12} , {0,9,1} , {0,9,9} };
	int Matrix1[3][3] = { {0,0,12} , {0,0,1} , {0,0,9} };

	cout << "\nMatrix1\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
	{
		cout << "\nYes: It is Sparse\n";
	}
	else
	{
		cout << "\nNo: It's NOT Sparse\n";
	}

	system("pause>0");
}
