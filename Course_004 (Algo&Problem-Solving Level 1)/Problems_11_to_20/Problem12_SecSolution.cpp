#include <iostream>
using namespace std;

int ReadNumbers()
{
    int Number;
    
	cout << "Please Enter a Number : " << endl;
	cin >> Number;
	
	return Number;
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

void PrintMaxOf2(int MaxNumber)
{
	cout << "The maximum Number = " << MaxNumber << endl;
}

int main()
{
	int Number1 = ReadNumbers();
	int Number2 = ReadNumbers();
	
	PrintMaxOf2(MaxOf2Numbers(Number1, Number2));

	return 0;

}
