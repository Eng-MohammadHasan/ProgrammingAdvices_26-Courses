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

	vNumbers.clear();

	//if(vNumbers.size() > 0){}

	//if (!vNumbers.empty()) {

	cout << "First Element : " << vNumbers.front() << endl;
	cout << "Last Element : " << vNumbers.back() << endl;

	//returns the number of elements present in vector 
	cout << "Size = " << vNumbers.size() << endl;

	//check the overall size of a vector 
	cout << "Capacity = " << vNumbers.capacity() << endl;

	//returns 1 (true) if the vector is empty
	cout << "Empty : " << vNumbers.empty() << endl;

	// }

	return 0;
}