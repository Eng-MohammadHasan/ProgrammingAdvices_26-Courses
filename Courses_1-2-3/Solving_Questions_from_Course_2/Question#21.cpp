#include <iostream>
#include <cmath>

using namespace std;

float CalculateCircleAreaAlongCircumference(float circle_Circumference)
{
	const float PI = 3.14;
	return (pow(circle_Circumference, 2)) / (4 * PI);
}
int main()
{
	float CircleCircumference;

	cout << "Please Enter Circle Circumference : " << endl;
	cin >> CircleCircumference;

	cout << "Circle Area = " << CalculateCircleAreaAlongCircumference(CircleCircumference) << endl;
	return 0;
}