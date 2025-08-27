#include <iostream>
using namespace std;

struct stEmployee
{
	string Name;
	float Salary;
};

int main()
{
	stEmployee Employee1, * ptr;

	Employee1.Name = "Mohammad Abu-Hadhoud";
	Employee1.Salary = 5000;

	// Accessing structure members directly
	cout << Employee1.Name << endl;
	cout << Employee1.Salary << endl;

	// Make pointer point to Employee1
	ptr = &Employee1;

	// Accessing structure members through pointer using ->
	cout << "\nUsing Pointer : \n";
	cout << ptr->Name << endl;
	cout << ptr->Salary << endl << endl;

	// Access addresses of structure members using object
	cout << &Employee1.Name << endl;
	cout << &Employee1.Salary << endl << endl;

	// Access addresses of structure members using pointer
	cout << &ptr->Name << endl;
	cout << &ptr->Salary << endl << endl;

	// Address of entire structure vs address of first member
	cout << &Employee1 << endl;
	cout << &Employee1.Name << endl << endl;

	// Pointer itself holds address of structure
	cout << ptr << endl;
	cout << &Employee1 << endl << endl;

	// Address of the pointer variable itself (not what it points to)
	cout << "Refrence of pointer that refer to the object of the struct : " << &ptr << endl << endl;

	// Two equivalent ways to access data through pointer
	cout << ptr->Name << endl;
	cout << (*ptr).Name << endl << endl;

	return 0;
}
