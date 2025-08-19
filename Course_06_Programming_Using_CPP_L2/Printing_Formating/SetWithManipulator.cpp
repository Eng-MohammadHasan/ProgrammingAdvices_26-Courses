#include <iostream>
#include <iomanip> // this library stored the std::setw
using namespace std;

int main()
{
	cout << "---------|--------------------------------|---------|" << endl;
	cout << "   Code  |              Name              |  Mark   |" << endl;
	cout << "---------|--------------------------------|---------|" << endl;
	cout << setw(9) << "C101" << "|" << setw(32) << "introduction to programming 1" << "|" << setw(9) << "95" << "|" << endl;
	cout << setw(9) << "C102" << "|" << setw(32) << "Computer Hardware" << "|" << setw(9) << "88" << "|" << endl;
	cout << setw(9) << "C10352" << "|" << setw(32) << "Network" << "|" << setw(9) << "75" << "|" << endl;
	cout << "---------|--------------------------------|---------|" << endl;

	// this what we fix up there ...

	/*cout << "C101" << "|" << "introduction to programming 1 " << "|" << 95 << "|" << endl;
	cout << "C102" << "|" << "Computer Hardware" << "|" << "88" << endl;
	cout << "C10352" << "|" << "Network" << "|" << "75" << "|" << endl;*/

	return 0;
}
