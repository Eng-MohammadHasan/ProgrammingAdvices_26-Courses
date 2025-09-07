#include <iostream>
#include <iomanip>
#include <vector>

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

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
}

bool IsNumberInVector(const vector<int>& vNumbers, int Number)
{
	for (const int& Num : vNumbers)
	{
		if (Num == Number)
			return true;
	}
	return false;
}

void FillVectorWithIntersectedNumbersInMatrices(vector <int>& vIntersectedNums, int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int CurrentNumber = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			CurrentNumber = Matrix1[i][j];
			if (IsNumberInMatrix(Matrix2, CurrentNumber, Rows, Cols) &&
				!IsNumberInVector(vIntersectedNums, CurrentNumber))
			{
				vIntersectedNums.push_back(CurrentNumber);
			}

		}
	}
}

void PrintVectorNumbers(const vector <int>& vIntersectedNums)
{
	cout << '\n';

	for (const int& Numbers : vIntersectedNums)
	{
		cout << Numbers << '\t';
	}
	cout << endl;
}

int main()
{
	int Matrix1[3][3] = { {77, 5 ,12} ,{22 ,20 , 1} , {1,0,9} };
	int Matrix2[3][3] = { {5, 80 ,90} ,{22 ,77 , 1} , {10,8,33} };

	vector <int> vIntersectedNums;

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	FillVectorWithIntersectedNumbersInMatrices(vIntersectedNums, Matrix1, Matrix2, 3, 3);

	cout << "\nIntersected Numbers are: \n";
	PrintVectorNumbers(vIntersectedNums);

	system("pause>0");
}
