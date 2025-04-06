#include <iostream>
using namespace std;

enum enMaritalStatus { Single, Married };
enum enGender { Male, Female };
enum enColor { Blue, Red, Yellow, Green };

struct stSalary
{
	float MonthlySalary;
	float YearlySalary;
	float BonusAmountOnSalary;
};

struct stAddress
{
	string Country;
	string City;
	string StreetName;
	string BuildingNumber;
	string POBox;
	string ZipCode;

};

struct stContactInfo
{
	string Email;
	string Phone1;
	string Phone2;
	string Instgram;
	string Facebook;

	stAddress Address;


};

struct stPerson
{

	string FirstName;
	string LastName;
	unsigned short Age;

	stContactInfo ContactInfo;
	stSalary Salary;

	enColor FavouriteColor;
	enMaritalStatus MaritalStatus;
	enGender Gender;

};

void ReadInfo(stPerson& Info)
{
	cout << "Please Enter your First Name : " << endl;
	cin >> Info.FirstName;

	cout << "Please Enter your Last Name : " << endl;
	cin >> Info.LastName;

	cout << "Please Enter your Age : " << endl;
	cin >> Info.Age;

	cout << "Please Enter your City : " << endl;
	cin >> Info.ContactInfo.Address.City;

	cout << "Please Enter your Country : " << endl;
	cin >> Info.ContactInfo.Address.Country;

	cout << "Please Enter your Monthly Salary : " << endl;
	cin >> Info.Salary.MonthlySalary;

	// Putting values hardcoded right now  :) 

	Info.Salary.YearlySalary = Info.Salary.MonthlySalary * 12;

	Info.Gender = enGender::Male;
	Info.MaritalStatus = enMaritalStatus::Married;
	Info.FavouriteColor = enColor::Blue;

}

void PrintInfo(stPerson Info)
{
	cout << "*************************************\n" << endl;
	cout << "Name : " << Info.FirstName << " " << Info.LastName << endl;
	cout << "Age : " << Info.Age << " years old." << endl;
	cout << "City : " << Info.ContactInfo.Address.City << endl;
	cout << "Country : " << Info.ContactInfo.Address.Country << endl;
	cout << "Monthly Salary : " << Info.Salary.MonthlySalary << endl;
	cout << "Yearly Salary : " << Info.Salary.YearlySalary << endl;

	// I know here it's going to print the value , but we're just practicing :)
	cout << "Gender : " << Info.Gender << endl;
	cout << "Married : " << Info.MaritalStatus << endl;
	cout << "Favourite color : " << Info.FavouriteColor << endl;
	cout << "*************************************\n" << endl;

}

int main()
{
	stPerson Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);

	stPerson Person2Info;
	ReadInfo(Person2Info);
	PrintInfo(Person2Info);

	return 0;
}