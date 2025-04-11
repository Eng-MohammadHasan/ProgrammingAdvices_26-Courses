#include <iostream>
#include <string>

using namespace std;

string ReadName()
{
	string UserName;

	cout << "Please Enter your Name : " << endl;
	getline(cin, UserName);

	return UserName;
}

void PrintName(string UserName)
{
	cout << "Your name is : " << UserName << endl;
}

int main()
{
	PrintName(ReadName());
}
