#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int& x = a; // Another name (alias) for the variable a , for the same memory slot!

	cout << &a << endl;
	cout << &x << endl;

	cout << a << endl;
	cout << x << endl;

	int* p = &a;

	cout << p << endl;
	cout << *p << endl;

	int b = 20;
	p = &b;

	cout << &b << endl;
	cout << p << endl;
	cout << *p << endl;

	return 0;

}
