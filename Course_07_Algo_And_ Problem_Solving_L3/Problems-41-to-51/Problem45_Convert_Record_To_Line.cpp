#include <iostream>
#include <string>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient ReadNewClient()
{
	sClient Client;

	cout << "Enter Account Number? ";
	getline(cin, Client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient ClientData, string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += ClientData.AccountNumber + Separator;
	stClientRecord += ClientData.PinCode + Separator;
	stClientRecord += ClientData.Name + Separator;
	stClientRecord += ClientData.Phone + Separator;
	stClientRecord += to_string(ClientData.AccountBalance);

	return stClientRecord;
}

int main()
{
	cout << "\nPlease Enter Client Data: \n\n";

	sClient Client;
	Client = ReadNewClient();

	cout << "\n\nClient Record for saving is : \n";
	cout << ConvertRecordToLine(Client);

	system("pause>0");

	return 0;
}