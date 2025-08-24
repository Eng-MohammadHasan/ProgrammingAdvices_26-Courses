#include <iostream>
using namespace std;

void Function(int x)
{
	x++;
	cout << "x address ... " << &x << endl;
}

void Function2(int& x)
{
	x++;
	cout << "x address ... " << &x << endl;
}

int main()
{
	int a = 10;

	cout << "Value of             a = " << a << endl;   
	cout << "Address/Reference of a = " << &a << endl; 

	Function(a);
	cout << a << endl;
	cout << "a adress : " << &a << endl;

	Function2(a);
	cout << a << endl;
	cout << "a adress : " << &a << endl;
	return 0;
}

