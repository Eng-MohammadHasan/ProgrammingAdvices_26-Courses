#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B, int& C)
{
	cout << "Please Enter Number 1 : " << endl;
	cin >> A;

	cout << "Please Enter Number 2 : " << endl;
	cin >> B;

	cout << "Please Enter Number 3 : " << endl;
	cin >> C;
}

int MaxOf3Numbers(int A, int B, int C)
{
	if (A > B)
	{
		if (A > C)
			return A;
		else
			return C;
	}
	else
	{
		if (B > C)
			return B;
		else
			return C;
	}
}

void PrintResults(int MaxNumber)
{
	cout << "\n The Maximum Number is : " << MaxNumber << endl;
}

int main()
{
	int A, B, C;
	ReadNumbers(A, B, C);
	PrintResults(MaxOf3Numbers(A, B, C));

	return 0;

}