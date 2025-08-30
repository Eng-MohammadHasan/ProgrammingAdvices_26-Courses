#include <iostream>

using namespace std;

int main()
{
	// declare an integer pointer 
	int* ptrX;

	// declare a float pointer
	float* ptrY;

	// dynamically allocate memory
	ptrX = new int;
	ptrY = new float;

	// assigning values to memory 
	*ptrX = 45;
	*ptrY = 58.35f;

	cout << *ptrX << endl;
	cout << *ptrX << endl;

	// deallcoate the memory
	delete ptrX;
	delete ptrY;

	return 0;
}
