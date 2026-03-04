#include <iostream>
using namespace std;

void ReadGrades(float Grades[3])
{
	cout << "Please Enter Grade 1 : \n";
	cin >> Grades[0];

	cout << "Please Enter Grade 2 : \n";
	cin >> Grades[1];

	cout << "Please Enter Grade 3 : \n";
	cin >> Grades[2];

}

float CalculateAverageGrades(float Grades[3])
{
	return (Grades[0] + Grades[1] + Grades[2]) / 3;
}


int main()
{
	float Grades[3];

	ReadGrades(Grades);
	cout << "*************************\n";
	cout << "The Average of Grades is : " << CalculateAverageGrades(Grades) << endl;

	return 0;
}