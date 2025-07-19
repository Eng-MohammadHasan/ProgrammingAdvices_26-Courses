#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
	float Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

float TotalBillAfterServiceAndTax(float TotalBill)
{
	float ServicesFee = 1.1, SalesTax = 1.16;

	TotalBill *= ServicesFee;
	TotalBill *= SalesTax;

	return TotalBill;

}


int main()
{
	float TotalBill = ReadPositiveNumber("Please Enter Total Bill : ");

	cout << endl;
	cout << "Total Bill = " << TotalBill << endl;
	cout << "Total Bill After Services Fee and Sales Tax = "
		<< TotalBillAfterServiceAndTax(TotalBill) << endl;

	return 0;
}