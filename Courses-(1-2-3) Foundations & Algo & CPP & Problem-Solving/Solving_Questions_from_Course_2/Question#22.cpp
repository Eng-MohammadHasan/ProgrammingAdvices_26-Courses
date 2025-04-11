#include <iostream>
#include <cmath>

using namespace std;

float CalculateCircleArea_InscribedInIsoscelesTriangle(float side_Of_Isosceles_Triangle, float base_Of_Isosceles_Triangle)
{
	const float PI = 3.14;
	float function1 = (PI * pow(base_Of_Isosceles_Triangle, 2) / 4);
	float function2 = ((2 * side_Of_Isosceles_Triangle) - base_Of_Isosceles_Triangle) / ((2 * side_Of_Isosceles_Triangle) + base_Of_Isosceles_Triangle);

	float circle_Area = function1 * function2;
	return circle_Area;
}
int main()
{
	float side_Of_Isosceles_Triangle, base_Of_Isosceles_Triangle;

	cout << "Please Enter the length of a side of the Isosceles Triangle : " << endl;
	cin >> side_Of_Isosceles_Triangle;

	cout << "Please Enter the Base of the Isosceles Triangle : " << endl;
	cin >> base_Of_Isosceles_Triangle;

	cout << "The Circle Area (Inscribed in an Isosceles Triangle ) = " << CalculateCircleArea_InscribedInIsoscelesTriangle(side_Of_Isosceles_Triangle, base_Of_Isosceles_Triangle) << endl;
	return 0;
}