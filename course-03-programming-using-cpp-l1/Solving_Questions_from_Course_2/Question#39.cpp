#include <iostream>
using namespace std;

int main()
{
	float TotalBill, CashPaid;

	cout << "Please Enter TotalBill : " << endl;
	cin >> TotalBill;
	
	cout << "Please Enter CashPaid : " << endl;
	cin >> CashPaid;
	
	float Remainder_For_Customer = (CashPaid - TotalBill);
	cout << "Remainder = " << Remainder_For_Customer << endl;
	return 0;
}

