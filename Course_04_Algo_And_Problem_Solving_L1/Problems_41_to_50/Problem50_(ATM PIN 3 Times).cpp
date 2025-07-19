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
	int Counter = 3;

	do
	{
		Counter--;
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			return true;
		}
		else
		{
			cout << "\nWrong PIN , you have " << Counter << " more tries \n";

		}

	} while (PinCode != "1234" && Counter >= 1);

	return false; // when you reach here this means login failed 
}

int main()
{

	if (Login())
	{
		system("color 2F"); //turn screen to green 
		cout << "\nYour account Balance is " << 7500 << '\n';
	}
	else
	{
		system("color 4F");
		cout << "\nYour Card is blocked . Call the bank for help. \n";
	}
	return 0;
}
