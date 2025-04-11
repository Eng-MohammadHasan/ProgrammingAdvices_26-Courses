#include <iostream>
using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

void ReadMarks(float Marks[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Please Enter mark # " << (i + 1) << " : " << endl;
		cin >> Marks[i];
	}
}

float CalculateSummationMarks(float Marks[3])
{
	float Sum = 0;

	for (int i = 0; i < 3; i++)
	{
		Sum += Marks[i];
	}

	return Sum;
}

float CalculateAverageMarks(float Marks[3])
{
	return CalculateSummationMarks(Marks) / 3;
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
	cout << "The Average of Entered marks = " << Average << endl;

	if (CheckAverage(Average) == enPassFail::Pass)
	{
		cout << "Pass" << endl;
	}
	else
	{
		cout << "Fail" << endl;
	}
}

int main()
{
	float Marks[3];

	ReadMarks(Marks);
	PrintResults(CalculateAverageMarks(Marks);

	return 0;
}
