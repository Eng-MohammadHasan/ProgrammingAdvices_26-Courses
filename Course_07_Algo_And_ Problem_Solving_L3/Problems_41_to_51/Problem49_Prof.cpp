#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

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

vector <string> SplitString(string S1, string Delimiter)
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

vector <sClient> LoadClientsDataFromFile(string FileName)
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

bool FindClientByAccountNumber(const string& AccountNumber, sClient& FoundClient)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

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

int main()
{
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();

	// It is better to load the vector of clients here ... and pass through parameter
	//vector<sClient> vClients = LoadClientsDataFromFile(ClientFileName);

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber <<
			") is Not Found!";
	}

	system("pause>0");
	return 0;
}