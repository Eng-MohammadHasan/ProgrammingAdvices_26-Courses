#include <iostream>
#include <vector>

using namespace std;

//No & → copies ... one loop variable reused ... same address every time.

//With &... reference to actual element ... different addresses(real vector storage).

int main() {
	vector<int> vNumbers = { 1,2,3,4,5 };
	vector<int>& vNumbersV2 = vNumbers;

	cout << "Not Using & in for loop" << endl;

	// vNumber Loop
	cout << "vNumber Loop : ";
	for (int Numbers : vNumbers) {
		cout << Numbers << " ";
		cout << &Numbers << " ";
	}
	cout << endl;

	// vNumberV2 Loop
	cout << "vNumberV2 Loop : ";
	for (int Numbers : vNumbersV2) {
		cout << Numbers << " ";
		cout << &Numbers << " ";
	}

	cout << endl << endl << endl;

	cout << "Using & in for loop" << endl;

	// vNumber Loop
	cout << "vNumber Loop : ";
	for (int& Numbers : vNumbers) {
		cout << Numbers << " ";
		cout << &Numbers << " ";
	}
	cout << endl;

	// vNumberV2 Loop
	cout << "vNumberV2 Loop : ";
	for (int& Numbers : vNumbersV2) {
		cout << Numbers << " ";
		cout << &Numbers << " ";
	}

	cout << endl << endl;

	return 0;
}
