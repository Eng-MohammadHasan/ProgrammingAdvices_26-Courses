#include <iostream>
using namespace std;

struct stPiggyBankContent
{
	int Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBankContent ReadPiggyBankContent()
{
	stPiggyBankContent PiggyBankContent;

	cout << "Please Enter total Pennies : \n";
	cin >> PiggyBankContent.Pennies;

	cout << "Please Enter total Nickels : \n";
	cin >> PiggyBankContent.Nickels;

	cout << "Please Enter total Dimes : \n";
	cin >> PiggyBankContent.Dimes;

	cout << "Please Enter total Quarters : \n";
	cin >> PiggyBankContent.Quarters;

	cout << "Please Enter total Dollars : \n";
	cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
	int TotalPennies = 0;

	TotalPennies = (PiggyBankContent.Pennies * 1) +
		(PiggyBankContent.Nickels * 5) +
		(PiggyBankContent.Dimes * 10) +
		(PiggyBankContent.Quarters * 25) +
		(PiggyBankContent.Dollars * 100);

	return TotalPennies;
}

//float CalculateTotalDollars(stPiggyBankContent Money, float TotalPennies)
//{
//	return TotalPennies / 100;
//}

int main()
{
	int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

	cout << endl << "Total Pinnies = " << TotalPennies << endl;
	cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;

	return 0;
}
