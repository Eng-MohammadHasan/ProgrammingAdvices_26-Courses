#include<iostream>
#include <vector>
#include <limits>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

int ReadNumber(string message)
{
	int Number = 0;
	cout << message;
	cin >> Number;

	while (cin.fail())
	{
		//user didn't input a number 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one : " << endl;

		cin >> Number;
	}

	return Number;
}

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

		// Read employee salary (validated input)
		tempEmployee.Salary = ReadNumber("Please Enter Employee Salary: ");

		vEmployees.push_back(tempEmployee);

		cout << "\nDo you want to add more employees? (Y/N)?\n";
		cin >> ReadMore;
	}
}

void PrintEmployeesInfo(const vector <stEmployee>& vEmployees)
{
	cout << "\nVector Employees : \n\n";

	for (const stEmployee& Employee : vEmployees)
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