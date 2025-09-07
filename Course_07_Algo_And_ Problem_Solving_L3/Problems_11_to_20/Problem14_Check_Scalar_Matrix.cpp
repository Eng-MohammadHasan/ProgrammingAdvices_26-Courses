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

bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int FirstDiagonalNumber = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//check for diagonals element
			if (i == j && Matrix1[i][j] != FirstDiagonalNumber)
			{
				return false;
			}
			//check for rest elements 
			else if (i != j && Matrix1[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	/*int Matrix1[3][3] =
	{

	 {1,2,3} ,
	 {4,5,6} ,
	 {7,8,9}

	};*/

	//int Matrix1[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };

	int Matrix1[3][3] = { {9,0,0} , {0,9,0} , {0,0,9} };

	cout << "\nMatrix\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
	{
		cout << "\nYES: Matrix is Scalar.\n";
	}
	else
	{
		cout << "\nNO: Matrix is NOT Scalar.\n";
	}

	system("pause>0");
}
