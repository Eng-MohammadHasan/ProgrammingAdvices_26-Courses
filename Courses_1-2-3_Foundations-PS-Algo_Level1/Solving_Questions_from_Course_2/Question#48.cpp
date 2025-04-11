#include <iostream>
using namespace std;

int main()
{
	float LoanAmount;
	int HowManyMonths;

	cout << "Please Enter the Loan Amount : " << endl;
	cin >> LoanAmount;

	cout << "Please Enter How Many Months you need to settle the Loan : " << endl;
	cin >> HowManyMonths;

	float MonthlyInstallmentAmount = LoanAmount / HowManyMonths;
	cout << "Your Monthly Installment Amount = \n" << MonthlyInstallmentAmount << endl;
	
	return 0;
}
