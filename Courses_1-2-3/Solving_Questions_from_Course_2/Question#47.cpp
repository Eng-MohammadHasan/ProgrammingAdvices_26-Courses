#include <iostream>
using namespace std;

int main()
{
	float LoanAmount , MonthlyInstallment;
	
	cout << "Please Enter the Loan Amout : " << endl;
	cin >> LoanAmount;

	cout << "Please Enter Your Monthly Payment : " << endl;
	cin >> MonthlyInstallment;

	float RemainingMonths = LoanAmount / MonthlyInstallment;

	cout << "Number of Remaining Months to settle the loan : ---> \n" << RemainingMonths << " Months Remaining" << endl;

	return 0;
}
