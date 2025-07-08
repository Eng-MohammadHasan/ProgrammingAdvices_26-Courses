#include <iostream>
using namespace std;

// void PrintNumbers(int A, int B)
// {
// 	cout << "**********\n";
// 	cout << A << endl;
// 	cout << B << endl;
// }

void Swap(int &A, int &B)
{
	int temp;

	temp = A;
	A = B;
	B = temp;

	cout << "After swap inside function A = " << A << ", B = " << B << endl;
}

int main()
{
	int A, B;

	cout << "Please Enter A :\n";
	cin >> A;
	cout << "Please Enter B :\n";
	cin >> B;

	cout << "Before swap A = " << A << ", B = " << B << endl;

	Swap(A, B);

	cout << "After swap inside the Main function A = " << A << ", B = " << B << endl;

	return 0;
}
