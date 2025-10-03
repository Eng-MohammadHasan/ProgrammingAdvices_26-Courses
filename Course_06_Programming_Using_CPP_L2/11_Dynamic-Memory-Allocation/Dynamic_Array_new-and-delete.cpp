#include <iostream>
using namespace std;

int main()
{
	int NumberOfStudents;

	cout << "Please enter total number of students ?\n";
	cin >> NumberOfStudents;

	float* ptr;

	// memory allocation of num (Numbers of floats)
	ptr = new float[NumberOfStudents];

	cout << "Enter grades of students? \n";

	for (int i = 0; i < NumberOfStudents; i++)
	{
		cout << "Student " << i + 1 << " : ";
		cin >> *(ptr + i);
	}

	cout << "\nDisplaying grades of students : \n";
	for (int i = 0; i < NumberOfStudents; i++)
	{
		cout << "Student " << i + 1 << " : " << *(ptr + i) << endl;
	}

	// ptr memory is released 
	delete[] ptr;

	return 0;
}
