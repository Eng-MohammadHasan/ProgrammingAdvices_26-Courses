#include <iostream>
#include <cmath>

using namespace std;

float ReadRadius()
{
	float Radius;

	cout << "Please Enter circle radius : " << endl;
	cin >> Radius;

	return Radius;
}

float CalculateCircleArea(float Radius)
{
	const float PI = 3.141592653589793238;

	return PI * pow(Radius, 2);
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResult(CalculateCircleArea(ReadRadius()));
	return 0;
}
