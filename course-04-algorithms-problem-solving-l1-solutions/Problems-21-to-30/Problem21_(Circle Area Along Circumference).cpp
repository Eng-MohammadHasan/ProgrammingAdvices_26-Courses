#include <iostream>
#include <cmath>

using namespace std;

float ReadCircumference()
{
	float Circumference;

	cout << "Please Enter Circle Circumference : \n";
	cin >> Circumference;

	return Circumference;
}

float CircleAreaByCircumference(float Circumference)
{
	const float PI = 3.141592653589793238;

	return pow(Circumference, 2) / (4 * PI);
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaByCircumference(ReadCircumference()));

	return 0;
}