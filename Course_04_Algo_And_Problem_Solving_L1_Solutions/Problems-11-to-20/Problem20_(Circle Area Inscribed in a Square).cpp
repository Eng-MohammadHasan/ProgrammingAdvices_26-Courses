#include <iostream>
#include <cmath>

using namespace std;

float ReadSquareSide()
{
	float SquareSide;

	cout << "Please Enter Square Side length = " << endl;
	cin >> SquareSide;

	return SquareSide;
}

float CircleAreaInscribedInSquare(float SquareSide)
{
	const float PI = 3.141592653589793238;

	return (PI * pow(SquareSide, 2)) / 4;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}


int main()
{
	PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

	return 0;
}
