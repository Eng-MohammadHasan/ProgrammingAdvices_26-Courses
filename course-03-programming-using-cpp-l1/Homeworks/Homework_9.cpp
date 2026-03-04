#include <iostream>
using namespace std;

struct ContactInformation {
	string Phone1;
	string Phone2;
	string Email1;
	string Facebook;
	string Instgram;
};

struct Address {
	string City;
	string Country;
	string street1;
	string street2;
	string POBOX;
};

struct Employee {
	unsigned int EmployeeID;
	string Name;
	unsigned short Age;
	float MonthlySalary;
	float YearlySalary;
	unsigned char Gender;
	bool isMarried;
	string JobTitle;
	string Department;
	Address address;
	ContactInformation contactInformation;
};

int main()
{

	Employee Employee1, Employee2;

	Employee1.EmployeeID = 1001;
	Employee1.Name = "Jenan";
	Employee1.Age = 23;
	Employee1.MonthlySalary = 20000;
	Employee1.YearlySalary = Employee1.MonthlySalary * 12;
	Employee1.Gender = 'F';
	Employee1.isMarried = true;
	Employee1.JobTitle = "architecture";
	Employee1.Department = "1";


	Employee1.address.City = "Amman";
	Employee1.address.Country = "Jordan";
	Employee1.address.street1 = "Street 1";
	Employee1.address.street2 = "Street 2";
	Employee1.address.POBOX = "12345";


	Employee1.contactInformation.Email1 = "Jojo@gmail.com";
	Employee1.contactInformation.Facebook = "JojoQamok";
	Employee1.contactInformation.Instgram = "JojoQamok";
	Employee1.contactInformation.Phone1 = "+962123456789";
	Employee1.contactInformation.Phone2 = "+962987654321";


	// Display Employee1 details
	cout << "***************************************\n";
	cout << "Name: " << Employee1.Name << endl;
	cout << "Age: " << Employee1.Age << " Years." << endl;
	cout << "City: " << Employee1.address.City << endl;
	cout << "Country: " << Employee1.address.Country << endl;
	cout << "Monthly Salary: " << Employee1.MonthlySalary << endl;
	cout << "Yearly Salary: " << Employee1.YearlySalary << endl;
	cout << "Gender: " << Employee1.Gender << endl;
	cout << "Married: " << (Employee1.isMarried ? "Yes" : "No") << endl;
	cout << "Job Title: " << Employee1.JobTitle << endl;
	cout << "Department: " << Employee1.Department << endl;
	cout << "***************************************\n";

	return 0;
}