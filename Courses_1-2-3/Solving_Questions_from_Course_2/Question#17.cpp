#include <iostream>
using namespace std;

int main()
{
	float triangle_Height, triangle_Base;

	cout << "Please enter triangle height :" << endl;
	cin >> triangle_Height;
	
	cout << "Please enter triangle Base :" << endl;
	cin >> triangle_Base;

	float triangle_Area = (0.5 * triangle_Height * triangle_Base);
	cout << "Triangle Area = " << triangle_Area << endl;

	return 0;
}
