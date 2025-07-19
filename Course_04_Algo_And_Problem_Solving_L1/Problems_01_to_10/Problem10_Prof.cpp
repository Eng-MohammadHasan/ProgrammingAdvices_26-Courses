#include <iostream>
using namespace std;

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

void PrintAverageMarks(float Average)
{
	cout << "The Average of Entered marks = " << Average << endl;
}

int main()
{
	float Marks[3];

	ReadMarks(Marks);
	PrintAverageMarks(CalculateAverageMarks(Marks));

	return 0;
}
