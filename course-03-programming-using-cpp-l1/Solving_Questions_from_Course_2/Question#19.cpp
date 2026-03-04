#include <iostream>
#include <cmath>

using namespace std;

float CalculateCircleArea(float CircleDiameter)
{
	const float PI = 3.14;
	return (PI * pow(CircleDiameter, 2)) / 4;

}

int main()
{

	float CircleDiameter;

	cout << "Please Enter circle diameter value : " << endl;
	cin >> CircleDiameter;

	cout << "Circle Area = " << CalculateCircleArea(CircleDiameter);

	return 0;
}
