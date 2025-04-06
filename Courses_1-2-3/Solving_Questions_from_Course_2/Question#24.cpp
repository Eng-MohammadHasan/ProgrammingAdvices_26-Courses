#include <iostream>
using namespace std;

void ReadAge(unsigned short& Age)
{
	cout << "Please Enter your Age : " << endl;
	cin >> Age;
}

string CheckAgeValidity(unsigned short Age)
{
	if (Age >= 18 && Age <= 45)
	{
		return "Valid Age :) ";
	}
	else
	{
		return "Invalid Age !";
	}
}

int main()
{
	unsigned short Age;

	ReadAge(Age);
	cout << "The Result : " << CheckAgeValidity(Age) << endl;

	return 0;
}
