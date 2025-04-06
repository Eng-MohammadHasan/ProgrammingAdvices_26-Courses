#include <iostream>
#include <string>

using namespace std;

string ReadName()
{
	string Name;

	cout << "Please Enter your Name : " << endl;
	getline(cin, Name);

	return Name;
}

void PrintName(string Name)
{
	cout << "\n Your name is : " << Name << endl;
}

int main()
{
	PrintName(ReadName());

	return 0;
}
