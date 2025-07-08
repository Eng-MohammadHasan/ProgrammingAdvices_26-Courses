#include <iostream>
#include <cmath>

using namespace std;

float NumberToThePowerOf_Two(float Number)
{
	return pow(Number, 2);
}

float NumberToThePowerOf_Three(float Number)
{
	return pow(Number, 3);
}

float NumberToThePowerOf_Four(float Number)
{
	return pow(Number, 4);
}

int main()
{
	float Number;

	cout << "Please Enter a Number : " << endl;
	cin >> Number;

	cout << "Number To The Power Of Two = " << NumberToThePowerOf_Two(Number) << endl;
	cout << "Number To The Power Of Three = " << NumberToThePowerOf_Three(Number) << endl;
	cout << "Number To The Power Of Four = " << NumberToThePowerOf_Four(Number) << endl;

	return 0;
}
