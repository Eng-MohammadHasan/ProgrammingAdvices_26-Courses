#include <iostream>
using namespace std;

int main()
{
	// Question Number 1 --->

		string Name = "Mohammad Abu-Hadhoud";
		unsigned short Age = 44;
		string City = "Amman";
		string Country = "Jordan";
		float MonthlySalary = 5000;
		char Gender = 'M';
		bool isMarried = true;
		float YearlySalary = (MonthlySalary * 12);

		cout << "***************************************\n";
		cout << "Name : " << Name << "\n";
		cout << "Age : " << Age <<" years old." <<"\n";
		cout << "City : " << City << "\n";
		cout << "Country : " << Country << "\n";
		cout << "MonthlySalary : " << MonthlySalary << "\n";
		cout << "YearlySalary : " << YearlySalary << "\n";
		cout << "Gender : " << Gender << "\n";
		cout << "Married : " << isMarried << "\n";
		cout << "***************************************\n";
		 
	// Question Number 2 --->
		short number1 = 20, number2 = 30, number3 = 10 ;
		//int summation = number1 + number2 + number3;

		cout << number1 << " + " << endl;
		cout << number2 << " + " << endl;
		cout << number3 << endl;
		cout << "-------------------" << endl;
		cout << number1 + number2 + number3 << endl;

	// Question Number 3 --->
		unsigned short MyAge = 25;
		unsigned short YourAgeAfter5Years = (MyAge + 5);

		cout << "After 5 years you will be " << (MyAge + 5) << " years old."<<endl;
		cout << "After 5 years you will be " << YourAgeAfter5Years << " years old:) ";
	return 0;	
}
