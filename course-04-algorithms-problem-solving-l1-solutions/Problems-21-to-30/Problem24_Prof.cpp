#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Please Enter your Age : " << endl;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

void PrintResult(bool AgeValidity)
{
	if (AgeValidity)
	{
		cout << "\nValid Age :) \n";
	}
	else
	{
		cout << "\nInvalid Age :( \n";
	}
}

int main()
{
	PrintResult(ValidateNumberInRange(ReadAge(), 18, 45));

	return 0;
}
