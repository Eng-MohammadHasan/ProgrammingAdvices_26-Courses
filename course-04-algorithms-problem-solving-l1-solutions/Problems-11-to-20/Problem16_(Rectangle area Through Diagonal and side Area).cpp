#include <iostream>
#include <cmath>

using namespace std;


void ReadNumbers(float& Width, float& Diagonal)
{
	cout << "Please Enter Rectangle width : " << endl;
	cin >> Width;

	cout << "Please Enter Rectangle diagonal : " << endl;
	cin >> Diagonal;
}

float RectangleAreaBySideAndDiagonal(float Width, float Diagonal)
{
	float Area;
	Area = Width * sqrt(pow(Diagonal, 2) - pow(Width, 2));

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}


int main()
{

	float Width, Diagonal;

	ReadNumbers(Width, Diagonal);
	PrintResult(RectangleAreaBySideAndDiagonal(Width, Diagonal));


	return 0;
}
