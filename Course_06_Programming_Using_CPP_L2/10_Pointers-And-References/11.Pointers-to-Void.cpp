#include <iostream>
#include <vector>

using namespace std;

struct stPersonInfo
{
	string FirstName;
	string LastName;
	string Address;
	long long PhoneNumber;
};

struct stPizza {
	string name;
	double price;
};

int main()
{
	void* ptr;
	float f1 = 10.5;
	int x = 50;


	//primitive data types
	ptr = &f1;

	cout << ptr << endl;
	cout << *(static_cast<float*>(ptr)) << endl;

	ptr = &x;

	cout << ptr << endl;
	cout << *(static_cast<int*>(ptr)) << endl;

	cout << "______________________________________________\n";

	//Structures
	stPersonInfo Person, * ptr2;
	Person.FirstName = "Mohammad";

	ptr = &Person;//Generic (void) Pointer
	ptr2 = &Person;

	cout << ptr2->FirstName << endl;
	cout << (static_cast<stPersonInfo*>(ptr))->FirstName << endl;

	cout << "______________________________________________\n";

	//Array
	int arr[3] = { 1,2,3 };
	ptr = arr;

	cout << (static_cast<int*>(ptr))[1] << endl; // prints 2

	cout << "______________________________________________\n";

	//Vector 
	vector <int> vNumbers;
	void* ptr4;
	ptr4 = &vNumbers;

	cout << (static_cast<vector<int>*>(ptr))->at(2); // prints 30

	//Vector of Structure
	vector<stPizza> vMenu = { {"Margherita", 5.5}, {"Pepperoni", 7.0} };
	void* ptr = &vMenu;

	cout << (static_cast<vector<stPizza>*>(ptr))->at(0).name << endl;  // prints Margherita

	return 0;
}
