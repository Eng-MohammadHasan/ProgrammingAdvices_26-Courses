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

float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
	return LoanAmount / HowManyMonths;
}

int main()
{

	float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount :");
	float HowManyMonths = ReadPositiveNumber("How many months do you need to settle the loan ?");

	cout << "\nMonthly Installment Amount = " << MonthlyInstallment(LoanAmount, HowManyMonths) << endl;




	return 0;
}
