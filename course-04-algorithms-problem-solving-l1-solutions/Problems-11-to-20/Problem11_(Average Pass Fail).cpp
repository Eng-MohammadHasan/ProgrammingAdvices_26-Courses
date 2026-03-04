#include <iostream>
using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please Enter Mark 1 : \n";
	cin >> Mark1;

	cout << "Please Enter Mark 2 : \n";
	cin >> Mark2;

	cout << "Please Enter Mark 3 : \n";
	cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMarks(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverage(float Average)
{
	if (Average >= 50)
	{
		return enPassFail::Pass;
	}
	else
	{
		return enPassFail::Fail;
	}
}

void PrintResults(float Average)
{
	cout << "\n The average of entered marks = " << Average << endl;

	if (CheckAverage(Average) == enPassFail::Pass)
	{
		cout << "\n You Passed" << endl;
	}
	else
	{
		cout << "\n You Failed" << endl;
	}

}

int main()
{
	int Number1, Number2, Number3;

	ReadMarks(Number1, Number2, Number3);
	PrintResults(CalculateAverageMarks(Number1, Number2, Number3));

	return 0;
}
