#include<iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	cout << "Stack Size = " << vNumbers.size() << endl;

	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();

	// Always before deleting from vector check if it's not empty using this..
	if (!vNumbers.empty())
	{
		vNumbers.pop_back();
	}

	cout << "Stack Size = " << vNumbers.size() << endl;

	// Or using this ...
	if (vNumbers.size() > 0)
	{
		vNumbers.pop_back();
	}

	// To clear The Whole vector stack ..
	vNumbers.clear();

	cout << "Numbers vectors : \n\n";

	// ranged loop
	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}

	cout << endl;

	return 0;
}