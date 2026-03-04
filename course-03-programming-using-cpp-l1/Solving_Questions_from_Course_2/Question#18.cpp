#include <iostream>
#include <cmath> 

using namespace std;

float CalculateCircleArea(float circleRadius)
{
	const float PI = 3.14;
	return PI * (pow(circleRadius, 2));

}
int main()
{
	const float PI = 3.14;
	float circleRadius;

	cout << "Please Enter circle radius value : " << endl;
	cin >> circleRadius;

	cout << "Circle Area = " << CalculateCircleArea(circleRadius) << endl;

	return 0;
}

