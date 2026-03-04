#include <iostream>
using namespace std;

void ReadRectangleSides(float& width, float& length)
{
	cout << "Please Enter Rectangle width ? " << endl;
	cin >> width;

	cout << "Please Enter Rectangle length ? " << endl;
	cin >> length;
}

float CalculateRectangleArea(float width, float length)
{
	return width * length;
}

void PrintRectangleArea(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}


int main()
{
	float width, length;

	ReadRectangleSides(width, length);
	PrintRectangleArea(CalculateRectangleArea(width, length));

	return 0;
}
