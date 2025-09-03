#include <iostream>
using namespace std;

void MyFunction()
{
	static int Number = 1;
	cout << Number << endl;

	Number++;
}

int main()
{
	MyFunction();
	MyFunction();
	MyFunction();

	return 0;
}
