#include <iostream>
#include <vector>

using namespace std;

void ReadVectorElements(vector<int>& vNumbers)
{
	char AddMore = 'Y';
	int Number = 0;

	do
	{
		cout << "Please enter a number : \n";
		cin >> Number;

		vNumbers.push_back(Number);

		cout << "Do you want to add more numbers (Y) or (N) : \n";
		cin >> AddMore;

	} while (AddMore != 'N' && AddMore != 'n');
}

void PrintVectorElements(vector<int> vNumbers)
{
	cout << "\n";

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
	cout << endl;
}

int main()
{
	vector <int> vNumbers;

	ReadVectorElements(vNumbers);
	PrintVectorElements(vNumbers);

	return 0;
}
