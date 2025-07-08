#include <iostream>
using namespace std;

struct strInfo
{
	string FirstName;
	string LastName;
	unsigned short Age;
	string phone;

};

void ReadInfo(strInfo& Info)
{
	cout << "Please Enter your first name : " << endl;
	cin >> Info.FirstName;

	cout << "Please Enter your last name : " << endl;
	cin >> Info.LastName;

	cout << "Please Enter your Age : " << endl;
	cin >> Info.Age;

	cout << "Please Enter your phone number : " << endl;
	cin >> Info.phone;

}

void PrintInfo(strInfo Info)
{
	cout << "\n**************************************\n";

	cout << "Your First Name is : " << Info.FirstName << endl;
	cout << "Your Last Name is : " << Info.LastName << endl;
	cout << "Your Age is : " << Info.Age << endl;
	cout << "Your Phone Number is : " << Info.phone << endl;

	cout << "\n**************************************\n";

}

int main()
{
	strInfo Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);

	strInfo Person2Info;
	ReadInfo(Person2Info);
	PrintInfo(Person2Info);

	return 0;
}
