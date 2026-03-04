#include <iostream>
#include <cmath>

using namespace std;

float ReadDiameter()
{
	float Diameter;

	cout << "Please Enter circle diameter : \n";
	cin >> Diameter;

	return Diameter;
}

float CircleAreaByDiameter(float Diameter)
{
	const float PI = 3.141592653589793238;

	return (PI * pow(Diameter, 2)) / 4;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaByDiameter(ReadDiameter()));

	return 0;
}
