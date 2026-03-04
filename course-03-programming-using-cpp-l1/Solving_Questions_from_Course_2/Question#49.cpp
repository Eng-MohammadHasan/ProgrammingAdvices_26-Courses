#include <iostream>
using namespace std;

void Read_ATM_Code(unsigned short& ATM_PIN_Code)
{
	cout << "Please Enter The PIN Code : \n";
	cin >> ATM_PIN_Code;
}

string Check_PIN_Eligibility(unsigned short ATM_PIN_Code, string Balance)
{
	if (ATM_PIN_Code == 1234)
	{
		return "Your Balance : " + Balance;
	}
	else
	{
		return "Wrong PIN ! (Enter the PIN again ... ) ";
	}
}

int main()
{
	unsigned short ATM_PIN_Code;
	string Balance = "7500";

	Read_ATM_Code(ATM_PIN_Code);
	cout << Check_PIN_Eligibility(ATM_PIN_Code, Balance) << endl;


	return 0; 
}
