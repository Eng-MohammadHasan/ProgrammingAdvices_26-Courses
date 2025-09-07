#include <iostream>
#include <cstdlib>
#include <ctime>

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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d\t", 2, arr[i][j]);
			//cout << setw(3) << arr[i][j] << '\t';
		}
		cout << '\n';
	}
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int Summation = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Summation += arr[i][j];
		}
	}

	return Summation;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	/*string EqualityResult = AreEqualMatrices(Matrix1, Matrix2, 3, 3) ? "Yes:matrices are equal" : "\n\nNO:matrices are NOT equal.";
	cout << EqualityResult << endl;*/

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
	{
		cout << "\nYES: both matrices are equal.";
	}
	else
	{
		cout << "\nNo: matrices are NOT equal.";
	}

	system("pause>0");
}