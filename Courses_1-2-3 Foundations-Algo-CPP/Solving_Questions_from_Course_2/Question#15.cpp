#include <iostream>
using namespace std;

float CalculateRectangleArea(float Rectangle_Height, float Rectangle_Length)
{
	return Rectangle_Height * Rectangle_Length;
}

int main()
{
	float Rectangle_Height, Rectangle_Length;

	cout << "Please Enter the rectangle length : " << endl;
	cin >> Rectangle_Length;

	cout << "Please Enter the rectangle height : " << endl;
	cin >> Rectangle_Height;

	cout << "Rectangle Area = " << CalculateRectangleArea(Rectangle_Height, Rectangle_Length) << endl;
	return 0;
}


