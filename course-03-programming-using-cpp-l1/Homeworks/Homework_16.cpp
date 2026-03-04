#include <iostream>
#include <string>

using namespace std;

struct strInfo
{
	string FirstName;
	string LastName;
	unsigned short Age;
	string Phone;
};

void ReadInfo(strInfo& Info)
{
	cout << "Please Enter your Frist Name : " << endl;
	cin >> Info.FirstName;

	cout << "Please Enter your Last Name : " << endl;
	cin >> Info.LastName;

	cout << "Please Enter your Age: " << endl;
	cin >> Info.Age;

	cout << "Please Enter your Phone Number : " << endl;
	cin >> Info.Phone;

}

void PrintInfo(strInfo Info)
{

	cout << "\n**********************************\n";

	cout << "FirstName: " << Info.FirstName << endl;
	cout << "LastName: " << Info.LastName << endl;
	cout << "Age: " << Info.Age << endl;
	cout << "Phone: " << Info.Phone << endl;

	cout << "\n**********************************\n";

}


void ReadPersonsInfo(strInfo People[2])
{
	ReadInfo(People[0]);
	ReadInfo(People[1]);
}

void PrintPersonsInfo(strInfo People[2])
{
	cout << "\n**********************************\n";

	PrintInfo(People[0]);
	PrintInfo(People[1]);
}

int main()
{
	strInfo Person;
	strInfo People[2];

	ReadPersonsInfo(People);
	PrintPersonsInfo(People);


	return 0;
}
