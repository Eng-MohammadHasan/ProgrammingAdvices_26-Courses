#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int b = 50;

	cout << "a value = " << a << endl;
	cout << "a address = " << &a << endl;

	int* p = &a;
	cout << "Pointer Value = " << p << endl;

	int* ptr;
	ptr = &a;

	cout << "Pointer Value = " << ptr << endl;

	ptr = &b;
	cout << "Pointer Value = " << ptr << endl;


	return 0;
}
