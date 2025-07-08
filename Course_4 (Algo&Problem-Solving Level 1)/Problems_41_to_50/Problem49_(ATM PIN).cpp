#include <iostream>
#include <string>

using namespace std;

string ReadPinCode()
{
	string PinCode;

	cout << "Please enter PIN code : \n";
	cin >> PinCode;

	return PinCode;
}

bool Login()
{
	string PinCode;

	do
	{
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			return 1; // this will exit the function and return true
		}
		else
		{
			cout << "\nWrong PIN\n";
			system("color 4F"); //turn screen to red 
		}

	} while (PinCode != "1234");

	return 0; // when you reach here this means login failed 
}

int main()
{

	if (Login())
	{
		system("color 2F"); //turn screen to green 
		cout << "Your account Balance is " << 7500 << '\n';
	}
	return 0;
}
