#include <iostream>
using namespace std;

struct strInfo
{
	unsigned short Age;
	bool DriverLicense;

};

void ReadInfo(strInfo& Person)
{
	cout << "Please Enter your Age : " << endl;
	cin >> Person.Age;

	cout << "Please Enter if you have a Driver License ... (Type (1) if yes ... , (0) if No ... ) :  " << endl;
	cin >> Person.DriverLicense;
}

string Check_Eligibility(strInfo Person)
{
	if (Person.Age > 21 && Person.DriverLicense == 1)
	{
		return "Hired :) ";
	}
	else
	{
		return "Rejected ! ";
	}
}

int main()
{
	strInfo Person1;
	ReadInfo(Person1);
	cout << "You are : " << Check_Eligibility(Person1);


	return 0;
}
