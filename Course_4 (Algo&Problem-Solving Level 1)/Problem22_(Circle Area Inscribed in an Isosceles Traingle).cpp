#include <iostream>
#include <cmath>

using namespace std;

void ReadTriangleData(float& Side, float& Base)
{
	cout << "Please Enter triangle side : \n";
	cin >> Side;

	cout << "Please Enter triangle base : \n";
	cin >> Base;
}

float CircleAreaByITriangle(float Side, float Base)
{
	const float PI = 3.141592653589793238;

	float Area;
	Area = PI * (pow(Base, 2) / 4) * ((2 * Side - Base) / (2 * Side + Base));

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	float Side, Base;

	ReadTriangleData(Side, Base);
	PrintResult(CircleAreaByITriangle(Side, Base));


	return 0;
}
