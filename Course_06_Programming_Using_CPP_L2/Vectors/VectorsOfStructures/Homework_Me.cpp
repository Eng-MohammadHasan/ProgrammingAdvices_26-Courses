#include<iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

void ReadEmployeesInfo(vector <stEmployee>& vEmployees)
{
	char ReadMore = 'Y';
	stEmployee tempEmployee;

	while (ReadMore == 'Y' || ReadMore == 'y')
	{
		cout << "Please Enter Employee First Name: ";
		cin >> tempEmployee.FirstName;

		cout << "Please Enter Employee Last Name: ";
		cin >> tempEmployee.LastName;

		cout << "Please Enter Employee Salary: ";
		cin >> tempEmployee.Salary;

		vEmployees.push_back(tempEmployee);

		cout << "\nDo you want to add more employees? (Y/N)?\n";
		cin >> ReadMore;
	}
}

void PrintEmployeesInfo(vector <stEmployee>& vEmployees)
{
	cout << "\nVector Employees : \n\n";

	for (stEmployee& Employee : vEmployees)
	{
		cout << "First Name : " << Employee.FirstName << endl;
		cout << "Last Name : " << Employee.LastName << endl;
		cout << "Salary : " << Employee.Salary << endl;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	// std::vector<T> vector_name;
	vector <stEmployee> vEmployees;

	ReadEmployeesInfo(vEmployees);
	PrintEmployeesInfo(vEmployees);

	return 0;
}