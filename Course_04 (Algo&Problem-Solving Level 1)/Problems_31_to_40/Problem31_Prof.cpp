#include <iostream>
#include <cmath>

using namespace std;


int ReadNumber()
{
	int Number;

	cout << "Please Enter a number : \n";
	cin >> Number;

	return Number;
}

int PowerOf2(int Number)
{
	return pow(Number, 2);
}

int PowerOf3(int Number)
{
	return pow(Number, 3);
}

int PowerOf4(int Number)
{
	return pow(Number, 4);
}

void PrintPowerOf2_3_4(int Number)
{
	cout << "Power of 2 : \n";
	cout << PowerOf2(Number) << endl;

	cout << "Power of 3 : \n";
	cout << PowerOf3(Number) << endl;

	cout << "Power of 4 : \n";
	cout << PowerOf4(Number) << endl;

}

int main()
{
	PrintPowerOf2_3_4(ReadNumber());


	return 0;
}
