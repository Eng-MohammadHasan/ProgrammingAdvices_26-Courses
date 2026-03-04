#include <iostream>
using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

int ReadMark()
{
	int Mark;

	cout << "Please Enter your mark : " << endl;
	cin >> Mark;

	return Mark;
}

enPassFail CheckMark(int Mark)
{
	if (Mark >= 50)
	{
		return enPassFail::Pass;
	}
	else
	{
		return enPassFail::Fail;
	}
}

void PrintResults(int Mark)
{
	if (CheckMark(Mark) == enPassFail::Pass)
	{
		cout << "\n You Passed" << endl;
	}
	else
	{
		cout << "You Failed" << endl;
	}
}


int main()
{

	PrintResults(ReadMark());

	return 0;
}
