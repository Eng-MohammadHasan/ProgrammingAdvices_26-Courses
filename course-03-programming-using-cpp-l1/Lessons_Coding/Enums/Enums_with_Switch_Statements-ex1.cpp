#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4 };

int main()
{
	cout << "*********************************\n";
	cout << "Please choose the number of your color : \n";
	cout << "(1) Red\n";
	cout << "(2) Blue\n";
	cout << "(3) Green\n";
	cout << "(4) Yellow\n";
	cout << "*********************************\n\n";
	cout << "Your Choice? ";

	int c;
	enScreenColor Color;

	cin >> c;
	Color = (enScreenColor)c;

	switch (Color)
	{

	case enScreenColor::Red:

		system("color 4F");
		break;

	case enScreenColor::Blue:

		system("color 1F");
		break;

	case enScreenColor::Green:

		system("color 2F");
		break;

	case enScreenColor::Yellow:

		system("color 6F");
		break;

	default:
		system("color 4F");
	}

	return 0;
}
