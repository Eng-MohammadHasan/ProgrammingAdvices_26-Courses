#include <iostream>
#include <cmath>

using namespace std;

float CalculateCircleAreaInscribedInSquare(float SquareLength)
{
	const float PI = 3.14;
	return (PI * pow(SquareLength, 2)) / 4;

}
int main()
{
	float SquareLength;

	cout << "Please Enter square side value : " << endl;
	cin >> SquareLength;

	cout << "Circle Area = " << CalculateCircleAreaInscribedInSquare(SquareLength) << endl;

	return 0;
}
