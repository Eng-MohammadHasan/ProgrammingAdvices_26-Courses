#include <iostream>

using namespace std;

int main()
{

	int Mark = 49;
	string result;

	//Using Short Hand If (Ternay Operator)
	result = (Mark >= 50) ? "Pass" : "Fail";
	cout << result << endl;

	(Mark >= 50) ? cout << "Pass" : cout << "Fail";


	// Homework
	string Result;

	cout << "\n\n";
	int Number;
	cin >> Number;

	Result = (Number > 0) ? "Positive" : "Negative";
	cout << "Number is :" << Result << endl;

	cout << "\n\n";

	Result = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");
	cout << "Number is :" << Result << endl;
	return 0;
}
