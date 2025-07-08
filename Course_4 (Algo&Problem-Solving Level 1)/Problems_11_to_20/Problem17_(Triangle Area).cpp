#include <iostream>
using namespace std;

void ReadNumbers(float& Base, float& Height)
{
	cout << "Please Enter Triangle Base : \n";
	cin >> Base;

	cout << "Please Enter Triangle Height : \n";
	cin >> Height;
}

float CalculateTriangleArea(float Base, float Height)
{

	float Area = (Base / 2) * Height;

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nArea = " << Area << endl;
}

int main()
{

	float Base, Height;

	ReadNumbers(Base, Height);
	PrintResult(CalculateTriangleArea(Base, Height));




	return 0;
}
