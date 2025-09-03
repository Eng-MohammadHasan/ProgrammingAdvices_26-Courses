#include<iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

int main()
{
	// std::vector <T> vector_name;
	vector <stEmployee> vEmployees;

	stEmployee tempEmployee;

	tempEmployee.FirstName = "Mohammad";
	tempEmployee.LastName = "Abu-Hadhoud";
	tempEmployee.Salary = 5000;
	vEmployees.push_back(tempEmployee);

	tempEmployee.FirstName = "Ali";
	tempEmployee.LastName = "Maher";
	tempEmployee.Salary = 2000;
	vEmployees.push_back(tempEmployee);


	tempEmployee.FirstName = "Aya";
	tempEmployee.LastName = "Omran";
	tempEmployee.Salary = 1000;
	vEmployees.push_back(tempEmployee);

	cout << "Employees Vector : \n\n";

	//ranged loop
	for (stEmployee& Employee : vEmployees)
	{
		cout << "First Name : " << Employee.FirstName << endl;
		cout << "Last Name : " << Employee.LastName << endl;
		cout << "Salaray : " << Employee.Salary << endl;
		cout << endl;
	}

	cout << endl;

	return 0;
}