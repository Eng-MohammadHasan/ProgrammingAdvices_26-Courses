#include <iostream>
#include <vector>
#include <limits> // for numeric_limits

using namespace std;

int ReadNumber()
{
	int Number = 0;
	cout << "Please enter a number ? \n";
	cin >> Number;
		
	while (cin.fail())
	{
		//user didn't input a number 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one : " << endl;
		
		cin >> Number;
	}
		
	return Number;
}

void ReadNumbers(vector<int>& vNumbers)
{
	char ReadMore = 'Y';
	int Number;

	while (ReadMore == 'Y' || ReadMore == 'y')
	{
		Number = ReadNumber();
		vNumbers.push_back(Number);

		cout << "\nDo you want to add more numbers ? Y/N: \n";
		cin >> ReadMore;
	}
}

void PrintVectorNumbers(const vector<int>& vNumbers)
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
