#include <iostream>
using namespace std;


void ReadNumbers(int& Number1, int& Number2)
{
	cout << "Please Enter Number 1 : " << endl;
	cin >> Number1;

	cout << "Please Enter Number 2 : " << endl;
	cin >> Number2;
}

void Swap(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

void PrintNumbers(int Number1, int Number2)
{
	cout << "\nNumber 1 = " << Number1 << endl;
	cout << "Number 2 = " << Number2 << endl;
}

int main()
{
	int Number1, Number2;

	ReadNumbers(Number1, Number2);
	PrintNumbers(Number1, Number2);
	Swap(Number1, Number2);
	PrintNumbers(Number1, Number2);

	return 0;
}
