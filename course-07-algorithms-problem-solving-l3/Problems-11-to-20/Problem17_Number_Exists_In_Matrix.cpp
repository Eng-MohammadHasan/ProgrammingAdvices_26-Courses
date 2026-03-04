#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int ReadNumber(string message)
{
	int Number = 0;
	cout << message;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max());
		cout << "Invalid Number, Enter a valid one : " << endl;

		cin >> Number;
	}
	return Number;

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

int main()
{
	int Matrix1[3][3] = { {77, 5 ,12} ,{22 ,20 , 1} , {1,0,9} };

	cout << "\nMatrix1\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = ReadNumber("\nPlease Enter the number to look for in matrix? ");

	if (IsNumberInMatrix(Matrix1, Number, 3, 3))
	{
		cout << "\nYes it is there.\n";
	}
	else
	{
		cout << "\nNo it is NOT there.\n";
	}

	system("pause>0");
}
