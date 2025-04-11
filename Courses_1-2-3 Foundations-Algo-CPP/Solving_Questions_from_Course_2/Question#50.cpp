#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PinCode;

	cout << "Please Enter your ATM PIN code : " << endl;
	cin >> PinCode;

	return PinCode;
}

bool Login()
{
	string PinCode;
	short Counter = 3;

	while (Counter > 0)
	{
		PinCode = ReadPinCode();
		Counter--;

		if (PinCode == "1234")
		{
			return true;
		}
		else
		{
			cout << "Wrong PIN , you have " << Counter << " more tries left" << endl;
		}
	}
	return false;
}

int main()
{
	if (Login())
	{
		cout << "Balance = " << 7500 << endl;
	}
	else
	{
		cout << "Your card is blocked. Call the bank for help." << endl;
	}
	return 0;
}

