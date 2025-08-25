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

	cout << a << endl;
	cout << x << endl;
	cout << y << endl;

	return 0;
}
