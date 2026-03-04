#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector<string> SplitString(string S1, string Delimiter)
{
	vector <string> vTokens;

	size_t pos = 0;
	string sWord;//define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delimiter)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);// store the word
		if (sWord != "")
		{
			vTokens.push_back(sWord);
		}

		//	S1 = S1.substr(pos + Delimiter.length());
		S1 = S1.erase(0, pos + Delimiter.length());
	}

	if (!S1.empty())
	{
		vTokens.push_back(S1); // it adds last word of the string.
	}

	return vTokens;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	if (vClientData.size() >= 5)
	{
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);//cast string to double
	}

	return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientCard(const sClient& Client)
{
	cout << "\n\nThe following are the client details : \n";

	cout << left << setw(18) << "\nAccout Number";
	cout << " : " << Client.AccountNumber;

	cout << setw(18) << "\nPin Code";
	cout << " : " << Client.PinCode;

	cout << setw(18) << "\nName";
	cout << " : " << Client.Name;

	cout << setw(18) << "\nAccout Phone";
	cout << " : " << Client.Phone;

	cout << setw(18) << "\nAccount Balance";
	cout << " : " << Client.AccountBalance;

}

bool FindClientByAccountNumber(const string& AccountNumber, const vector<sClient>& vClients, sClient& FoundClient)
{
	for (const sClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			FoundClient = Client;
			return true;
		}
	}

	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Account Number? ";
	cin >> AccountNumber;

	return AccountNumber;
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

vector<sClient> DeleteClient(sClient& Client, vector<sClient>& vClients)
{
	vector<sClient> vClientsAfterDeletion;

	for (sClient& C : vClients)
	{
		if (C.AccountNumber != Client.AccountNumber)
		{
			vClientsAfterDeletion.push_back(C);
		}
	}

	return vClientsAfterDeletion;
}

void SaveVectorToFile(const string& FileName, const vector<sClient>& vClientsAfterDeletion)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (const sClient& Client : vClientsAfterDeletion)
		{
			string stLine = ConvertRecordToLine(Client);
			MyFile << stLine << endl;
		}

		MyFile.close();
	}
}

void DeleteClientFromFile(const string& FileName, sClient& Client, vector<sClient>& vClients)
{
	char DeleteChoice;

	cout << "\n\nAre you sure you want to delete this client? y/n ? ";
	cin >> DeleteChoice;

	if (toupper(DeleteChoice) == 'Y')
	{
		vector<sClient> vClientsAfterDeletion = DeleteClient(Client, vClients);
		SaveVectorToFile(FileName, vClientsAfterDeletion);

		cout << "\n\nClient Deleted Successfully.";
	}
}

int main()
{
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		DeleteClientFromFile(ClientsFileName, Client, vClients);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber <<
			") is Not Found!";
	}

	system("pause>0");
	return 0;
}