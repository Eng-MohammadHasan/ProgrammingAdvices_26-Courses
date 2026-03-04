#include <iostream>
using namespace std;

enum enCountryChoice { Jordan = 1, Tunisia = 2, Algeria = 3, Oman = 4, Egypt = 5, Iraq = 6, other = 7 };


int main()
{
	cout << "**********************************\n";
	cout << "Please Enter the number of your country : \n";
	cout << "(1) Jordan\n";
	cout << "(2) Tunisia\n";
	cout << "(3) Algeria\n";
	cout << "(4) Oman\n";
	cout << "(5) Egypt\n";
	cout << "(6) Iraq\n";
	cout << "(7) Other\n";
	cout << "**********************************\n\n";
	cout << "Your Choice : ";


	unsigned short choice;
	cin >> choice;

	enCountryChoice Country;
	Country = (enCountryChoice)choice; // Casting :) 

	if (Country == enCountryChoice::Jordan)
	{
		cout << "your country is Jordan\n";
	}
	else if (Country == enCountryChoice::Tunisia)
	{
		cout << "your country is Tunisia\n";
	}
	else if (Country == enCountryChoice::Algeria)
	{
		cout << "your country is Algeria\n";
	}
	else if (Country == enCountryChoice::Oman)
	{
		cout << "your country is Oman\n";
	}
	else if (Country == enCountryChoice::Egypt)
	{
		cout << "your country is Egypt\n";
	}
	else if (Country == enCountryChoice::Iraq)
	{
		cout << "your country is Iraq\n";
	}
	else
	{
		cout << "The country is Other\n";
	}

	return 0;
}