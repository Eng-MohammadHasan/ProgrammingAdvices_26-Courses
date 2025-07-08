#include <iostream>
using namespace std;

int main()
{
	// Question Number 1 ---> 

		string Name , City , Country ;
		unsigned short Age;
		float MonthlySalary;
		char Gender;
		bool isMarried;


		cout << "Please Enter your name : " << endl;
		cin >> Name;

		cout << "Please Enter your Age : " << endl;
		cin >> Age;

		cout << "Please Enter your City : " << endl;
		cin >> City;

		cout << "Please Enter your Country : " << endl;
		cin >> Country;

		cout << "Please Enter your MonthlySalary : " << endl;
		cin >> MonthlySalary;

		cout << "Please Enter your Gender M/F ? " << endl;
		cin >> Gender;

		cout << "Are you Married ? 1/0 ? " << endl;
		cin >> isMarried;


		cout << "*******************************\n";
		cout << "Name : " << Name << endl;
		cout << "Age : " << Age << endl;
		cout << "City : " << City << endl;
		cout << "Country : " << Country << endl;
		cout << "MonthlySalary : " << MonthlySalary << endl;
		cout << "YearlySalary : " << (MonthlySalary * 12) << endl;
		cout << "Gender : " << Gender << endl;
		cout << "Married : " << isMarried << endl;
		cout << "*******************************\n";


	// Question Number 2 ---> 
		
		short Number1, Number2 , Number3 ;
		
		cout << "Please Enter the first Number : " << endl;
		cin >> Number1;
		
		cout << "Please Enter the seconde Number : " << endl;
		cin >> Number2;

		cout << "Please Enter the third Number : " << endl;
		cin >> Number3;

		short summation = Number1 + Number2 + Number3;

		cout << Number1 << " + " << endl;
		cout << Number2 << " + " << endl;
		cout << Number3 << endl;
		cout << "--------------------------" << endl;

		cout << "Total = " << summation << "\n";
		
	// Question Number 3 --->
		
		unsigned short UserAge;

		cout << "Please Enter your Age : " << endl;
		cin >> UserAge;

		unsigned short YourAgeAfter5Years = (UserAge + 5 ) ;
		cout << "After 5 years you will be " << YourAgeAfter5Years << " years old." << endl;

		return 0;
}
