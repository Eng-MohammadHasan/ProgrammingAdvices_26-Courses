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

float CalculateRemainder(float TotalBill, float TotalCashPaid)
{
	return TotalCashPaid - TotalBill;
}


int main()
{
	float TotalBill = ReadPositiveNumber("Please Enter Total Bill : ");

	float TotalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid : ");

	cout << endl;
	cout << "Total Bill = " << TotalBill << endl;
	cout << "Total Cash Paid = " << TotalCashPaid << endl;

	cout << "***********************\n";
	cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

	return 0;

}
