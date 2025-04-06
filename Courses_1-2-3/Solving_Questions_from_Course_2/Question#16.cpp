#include <iostream>
#include <cmath>

using namespace std;

float CalculateRectangleArea(float RectangleSideLegth, float RectangleDiagnolLength)
{
	return  RectangleSideLegth * (sqrt(pow(RectangleDiagnolLength, 2) - pow(RectangleSideLegth, 2)));
}

int main()
{
	float RectangleSideLegth, RectangleDiagnolLength, RectangleArea;

	cout << "Please Enter one rectangle side length : " << endl;
	cin >> RectangleSideLegth;

	cout << "Please Enter rectangle diagnol length : " << endl;
	cin >> RectangleDiagnolLength;

	cout << "Rectangle Area = " << CalculateRectangleArea(RectangleSideLegth, RectangleDiagnolLength) << endl;

	return 0;
}
