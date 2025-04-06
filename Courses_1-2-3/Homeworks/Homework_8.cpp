#include <iostream>
using namespace std;

// This Homework is a Coding Solution for the previous Homework in {Course 1} ... (CH 16) :) 

int main()
{
	cout << ((5 > 6 && 7 == 7) || (1 || 0)) << endl;
	cout << (!(5 > 6 && 7 == 7) || (1 || 0)) << endl;
	cout << (!(5 > 6 && 7 == 7) || !(1 || 0)) << endl;
	cout << (!(5 > 6 && 7 == 7) && !(1 || 0)) << endl;
	cout << ((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3) && true) << endl;
	cout << (((5 > 6) && !(7 <= 8)) && (8 > 1 || 4 <= 3) || true) << endl;
	
	return 0;
}
