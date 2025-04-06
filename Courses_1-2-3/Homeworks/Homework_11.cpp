#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "43.22";

	int num_int = stoi(str);   // Will be 43
	float num_float = stof(str);
	double num_double = stod(str);

	cout << "Integer: " << num_int << endl;
	cout << "Float: " << num_float << endl;
	cout << "Double: " << num_double << endl;

	int N1 = 20;
	string st1 = to_string(N1);

	double N2 = 33.5;
	string st2 = to_string(N2);

	float N3 = 55.23;
	string st3 = to_string(N3);

	// int N3_toInt = N3; // Implicit conversion
	int N3_toInt = (int)N3;  // Truncate decimal part
	//int N3_toInt = int (N3);
	cout << "Float to int: " << N3_toInt << endl;

	return 0;
}
