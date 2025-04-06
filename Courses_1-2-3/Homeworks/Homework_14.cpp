#include <iostream>
using namespace std;


int mySumFunction(int Number1, int Number2)
{
	return Number1 + Number2;
}

int main()
{
	int Number1, Number2;

	cout << "Please Enter first Number : " << endl;
	cin >> Number1;

	cout << "Please Enter second Number : " << endl;
	cin >> Number2;

	cout << mySumFunction(Number1, Number2) << endl;

	return 0;
}
