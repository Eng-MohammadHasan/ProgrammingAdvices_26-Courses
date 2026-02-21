#include <iostream>
#include <iomanip>
#include <limits>

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

int main()
{
	int Matrix1[3][3] = { {9,1,12} , {0,9,1} , {0,9,9} };

	cout << "\nMatrix\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number = ReadNumber("\nPlease Enter the number to count in matrix? ");

	cout << "\nNumber " << Number << " count in matrix is : "
		<< CountNumberInMatrix(Matrix1, Number, 3, 3);

	system("pause>0");
}
