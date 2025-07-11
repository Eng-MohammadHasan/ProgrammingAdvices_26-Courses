#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter a number :\n";
	cin >> Number;

	return Number;
}

float MyABS(float Number)
{
	if (Number >= 0)
	{
		return Number;
	}
	else
	{
		// return -Number or 0 - Number ;
		return Number * -1;
	}
}

int main()
{

	float Number = ReadNumber();

	cout << "My abs Result : " << MyABS(Number) << endl;
	cout << "C++ abs Result : " << abs(Number) << endl;

	return 0;
}
