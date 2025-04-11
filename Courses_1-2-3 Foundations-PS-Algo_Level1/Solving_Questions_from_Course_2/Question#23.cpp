#include <iostream>
#include <cmath>

using namespace std;

float CalculateCircleArea_DescribedAround_AnArbitraryTriangle(float triangleSide1, float triangleSide2, float triangleSide3)
{
	const float PI = 3.14;
	float p, circleArea;

	p = (triangleSide1 + triangleSide2 + triangleSide3) / 2;
	circleArea = PI * (pow((triangleSide1 * triangleSide2 * triangleSide3) / (4 * sqrt(p * (p - triangleSide1) * (p - triangleSide2) * (p - triangleSide3))), 2));

	return circleArea;
}

int main()
{

	float triangleSide1, triangleSide2, triangleSide3;

	cout << "Please Enter the first triangle side value : " << endl;
	cin >> triangleSide1;

	cout << "Please Enter the second triangle side value : " << endl;
	cin >> triangleSide2;

	cout << "Please Enter the third triangle side value : " << endl;
	cin >> triangleSide3;

	cout << "circle area = " << CalculateCircleArea_DescribedAround_AnArbitraryTriangle(triangleSide1, triangleSide2, triangleSide3) << endl;

	return 0;
}
