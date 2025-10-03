#include <iostream>
using namespace std;

int main()
{
	int arr[4] = { 10 , 20 , 30 ,40 };
	int* ptr;
	ptr = arr;

	//ptr is equivalent to &arr[0]
	//ptr + 1 is equivalent to &arr[1]
	//ptr + 2 is equivalent to &arr[2]
	//ptr + 3 is equivalent to &arr[3]

	/*for (int& Items : arr)
	{
		cout << &Items << endl;
		cout << &arr[i] << endl;
		i++;
	
		cout << endl;
	}
	cout << endl << endl;*/

	cout << "Addresses are :\n";
	cout << ptr << endl;
	cout << ptr + 1 << endl;
	cout << ptr + 2 << endl;
	cout << ptr + 3 << endl;

	//cout << "\nValues are: \n";
	cout << *(ptr) << endl;
	cout << *(ptr + 1) << endl;
	cout << *(ptr + 2) << endl;
	cout << *(ptr + 3) << endl;

	// or like this ...
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << *(ptr + i) << endl;
	}

	cout << arr << endl;
	cout << &arr[0] << endl;
	cout << &arr << endl;
	return 0;
}
