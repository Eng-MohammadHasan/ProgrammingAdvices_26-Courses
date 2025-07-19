#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
	float Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float TotalMonths(float LoanAmount, float MonthlyInstallment)
{
	return LoanAmount / MonthlyInstallment;
}


int main()
{
	float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount :");
	float  MonthlyInstallment = ReadPositiveNumber("Please Enter Monthly Installment : ");

	cout << "\nTotal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallment) << " Months" << endl;


	return 0;
}
