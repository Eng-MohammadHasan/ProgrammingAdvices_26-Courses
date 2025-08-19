#include <iostream>
#include <vector>

using namespace std;

void ReadNumbers(vector<int>& vNumbers)
{
	char ReadMore = 'Y';
	int Number;

	while (ReadMore == 'Y' || ReadMore == 'y')
	{
		cout << "Please Enter a number \n";
		cin >> Number;

		vNumbers.push_back(Number);

		cout << "\nDo you want to add more numbers ? Y/N: \n";
		cin >> ReadMore;
	}
}

void PrintVectorNumbers(vector<int>& vNumbers)
{
	cout << "\n";
	cout << "Numbers vector : \n";

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
	cout << endl;
}

int main()
{

	vector <int> vNumbers;

	ReadNumbers(vNumbers);
	PrintVectorNumbers(vNumbers);

	return 0;
}