#include <iostream>
using namespace std;

void ReadNumbers(int& Number1, int& Number2)
{
	cout << "Please Enter Number 1 : " << endl;
	cin >> Number1;

	cout << "Please Enter Number 2 : " << endl;
	cin >> Number2;
}

int MaxOf2Numbers(int Number1, int Number2)
{
	if (Number1 > Number2)
	{
		return Number1;
	}
	else
	{
		return Number2;
	}
}

void PrintResults(int MaxNumber)
{
	cout << "\n The Maximum Number is : " << MaxNumber << endl;
}

int main()
{
	int Number1, Number2;
	ReadNumbers(Number1, Number2);
	PrintResults(MaxOf2Numbers(Number1, Number2));

	return 0;

}