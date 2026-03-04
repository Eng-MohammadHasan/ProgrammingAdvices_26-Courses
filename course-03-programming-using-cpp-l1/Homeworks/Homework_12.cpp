#include <iostream>
#include <string>

using namespace std;

int main()
{
	string String1, String2, String3;

	cout << "Please Enter String1 : " << endl;
	getline(cin, String1);

	cout << "Please Enter String2 : " << endl;
	cin >> String2;

	cout << "Please Enter String3 : " << endl;
	cin >> String3;

	cout << "\n*****************************************************\n";
	cout << "The Length of String1 is " << String1.length() << endl;
	cout << "Characters at 0,2,4,7 are : " << String1[0] << " " << String1[2] << " " << String1[4] << " " << String1[7] << endl;
	cout << "Concatenating String2 and String3 = " << String2 + String3 << endl;

	int Result = stoi(String2) + stoi(String3);

	cout << String2 << " * " << String3 << " = " << Result << endl;


	return 0;
}
