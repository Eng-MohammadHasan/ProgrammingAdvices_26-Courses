#include <iostream>
#include <string>

using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please Enter your First Name : \n";
	cin >> Info.FirstName;

	cout << "Please Enter your First Name : \n";
	cin >> Info.LastName;

	return Info;
}

string GetFullName(stInfo Info, bool IsReversed)
{
	string FullName = "";

	if (IsReversed)
	{
		FullName = Info.LastName + " " + Info.FirstName;
	}
	else
	{
		FullName = Info.FirstName + " " + Info.LastName;
	}

	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "\n Your full name is : " << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadInfo(), true));

	return 0;

}
