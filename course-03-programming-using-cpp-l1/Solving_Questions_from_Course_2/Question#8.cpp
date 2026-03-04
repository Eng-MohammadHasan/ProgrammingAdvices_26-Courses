#include <iostream>
using namespace std;


void ReadMark(float& Mark)
{
	cout << "Please Enter your Mark : " << endl;
	cin >> Mark;
}

string CheckResult(float Mark)
{
	if (Mark >= 50)
	{
		return "Pass :) ";
	}
	else
	{
		return "Fail ! ";
	}
}


int main()
{
	float Mark;
	ReadMark(Mark);
	cout << "The Result : " << CheckResult(Mark) << endl;

	return 0;
}