#include <iostream>
using namespace std;


int main()
{
	int a = 10;
	int& x = a;
	int y = a;

	cout << &a << endl;
	cout << &x << endl;
	cout << &y << endl;

	cout << "a = " << a << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << endl;

	x = 20;

	cout << "a = " << a << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << endl;

	a = 30;

	cout << "a = " << a << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << endl;

	return 0;
}
