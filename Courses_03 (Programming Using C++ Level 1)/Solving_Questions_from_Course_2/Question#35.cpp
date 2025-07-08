#include <iostream>
using namespace std;

int main()
{
	// Piggy Bank Calculator ...

	unsigned short  Pennies, Nickels, Dimes, Quarters, Dollars;
	
	cout << "Please Enter Number of Pennies :" << endl;
	cin >> Pennies;
	
	cout << "Please Enter Number of Nickels :" << endl;
	cin >> Nickels;
	
	cout << "Please Enter Number of Dimes :" << endl;
	cin >> Dimes;
	
	cout << "Please Enter Number of Quarters :" << endl;
	cin >> Quarters;

	cout << "Please Enter Number of Dollars :" << endl;
	cin >> Dollars;
	
	float TotalPennies = ((Pennies)+(Nickels * 5) + (Dimes * 10) + (Quarters * 25) + (Dollars * 100));
	float TotalDollars = TotalPennies / 100;
	
	cout << TotalPennies << " Pennies" << endl;
	cout << TotalDollars << " Dollars " << endl;	
	return 0;
}
