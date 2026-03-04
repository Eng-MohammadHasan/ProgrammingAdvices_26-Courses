#include <iostream>
#include <cmath>

using namespace std;

float ReturnPowerOfNumber(float Number, unsigned short Power)
{
	return pow(Number, Power);
}
int main()
{
	float Number;
	unsigned short M;

	cout << "Please Enter a Number : " << endl;
	cin >> Number;

	cout << "Please Enter the power : " << endl;
	cin >> M;

	cout << "Result = " << ReturnPowerOfNumber(Number, M);

	return 0;
}
