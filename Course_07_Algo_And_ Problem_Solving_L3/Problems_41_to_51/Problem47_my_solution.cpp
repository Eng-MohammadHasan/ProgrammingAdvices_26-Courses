#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FileName = "Clients.txt";

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

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

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

vector<string> AddClients()
{
	vector<string> vClientsRecords;
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client: \n\n";

		sClient Client = ReadNewClient();
		string NewLine = ConvertRecordToLine(Client);
		vClientsRecords.push_back(NewLine);

		cout << "\n\nClient Added Successfully, do you want to add more clients?\n";
		cin >> AddMore;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (AddMore == 'Y' || AddMore == 'y');

	return vClientsRecords;
}

void SaveClientsRecordsToFile(const vector<string>& vClientsRecords)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (const string& Record : vClientsRecords)
		{
			MyFile << Record << endl;
		}

		MyFile.close();
	}
}

int main()
{
	vector<string> vClientsRecords = AddClients();
	SaveClientsRecordsToFile(vClientsRecords);

	system("pause>0");
	return 0;
}
