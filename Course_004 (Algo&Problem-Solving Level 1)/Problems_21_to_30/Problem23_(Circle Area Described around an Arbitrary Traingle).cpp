#include <iostream>
#include <cmath>

using namespace std;

void ReadTriangleData(float& Side1, float& Side2, float& Side3)
{
	cout << "Please Enter Triangle Side 1 length = " << endl;
	cin >> Side1;

	cout << "Please Enter Triangle Side 2 length = " << endl;
	cin >> Side2;

	cout << "Please Enter Triangle Side 3 length = " << endl;
	cin >> Side3;
}

float CircleAreaByATriangle(float Side1, float Side2, float Side3)
{
	const float PI = 3.141592653589793238;
	float P;
	P = (Side1 + Side2 + Side3) / 2;

	float T;
	T = (Side1 * Side2 * Side3) / (4 * sqrt(P * (P - Side1) * (P - Side2) * (P - Side3)));

	float Area = PI * pow(T, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}
int main()
{

	float Side1, Side2, Side3;

	ReadTriangleData(Side1, Side2, Side3);
	PrintResult(CircleAreaByATriangle(Side1, Side2, Side3));


	return 0;
}
