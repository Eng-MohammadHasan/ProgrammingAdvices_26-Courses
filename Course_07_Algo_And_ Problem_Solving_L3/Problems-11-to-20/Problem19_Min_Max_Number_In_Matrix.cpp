#include <iostream>
#include <iomanip>

using namespace std;

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

int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int MinNumber = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] < MinNumber)
			{
				MinNumber = Matrix1[i][j];
			}
		}
	}

	return MinNumber;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int MaxNumber = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] > MaxNumber)
			{
				MaxNumber = Matrix1[i][j];
			}
		}
	}

	return MaxNumber;
}

int main()
{
	int Matrix1[3][3] = { {77, 5 ,12} ,{22 ,20 , 6} , {14,3,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum Number is: ";
	cout << MinNumberInMatrix(Matrix1, 3, 3);

	cout << "\n\nMaximum Number is: ";
	cout << MaxNumberInMatrix(Matrix1, 3, 3);

	system("pause>0");
}
