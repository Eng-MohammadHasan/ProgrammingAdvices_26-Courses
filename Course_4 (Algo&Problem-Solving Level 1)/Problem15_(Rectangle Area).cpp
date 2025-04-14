#include <iostream>
using namespace std;

void ReadRectangleSides(float& A, float& B)
{
	cout << "Please Enter Rectangle width ? " << endl;
	cin >> A;

	cout << "Please Enter Rectangle length ? " << endl;
	cin >> B;
}

float CalculateRectangleArea(float A, float B)
{
	return A * B;
}

void PrintRectangleArea(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}


int main()
{
	float A, B;

	ReadRectangleSides(A, B);
	PrintRectangleArea(CalculateRectangleArea(A, B));

	return 0;
}
