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

	unsigned short Choice;
	cin >> Choice;

	enCountryChoice Country;
	Country = (enCountryChoice)Choice;

	switch (Country)
	{
	case enCountryChoice::Jordan:
		cout << "your country is Jordan\n";
		break;

	case enCountryChoice::Tunisia:
		cout << "your country is Tunisia\n";
		break;

	case enCountryChoice::Algeria:
		cout << "your country is Algeria\n";
		break;

	case enCountryChoice::Oman:
		cout << "your country is Oman\n";
		break;

	case enCountryChoice::Egypt:
		cout << "your country is Egypt\n";
		break;

	case enCountryChoice::Iraq:
		cout << "your country is Iraq\n";
		break;

	default:
		cout << "The country is other\n";
	}
	return 0;
}
