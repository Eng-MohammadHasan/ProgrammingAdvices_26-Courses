#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

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
	sClient Client{};
	vector<string> vClientData = SplitString(Line, Seperator);

	if (vClientData.size() >= 5)
	{
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];

		try { Client.AccountBalance = stod(vClientData[4]); }
		catch (...) { Client.AccountBalance = 0; }
	}

	return Client;
}

vector<string> LoadClientsFromFile(string FileName)
{
	vector <string> vClientsRecords;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vClientsRecords.push_back(Line);
		}

		MyFile.close();
	}

	return vClientsRecords;
}

vector<sClient> GetClients()
{
	vector<sClient> vClients;

	vector<string> vClientsRecords = LoadClientsFromFile(ClientsFileName);
	for (string& Line : vClientsRecords)
	{
		vClients.push_back(ConvertLineToRecord(Line));
	}

	return vClients;
}

void TableHeader()
{
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << left << setw(15) << "| Account Number ";
	cout << setw(10) << "| Pin Code ";
	cout << setw(40) << "| Client Name ";
	cout << setw(12) << "| Phone ";
	cout << setw(12) << "| Balance ";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientCard(const sClient& Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(const vector<sClient>& vClients)
{
	cout << "\n\t\t\t\tClient List ( " << vClients.size() << " ) Client(s).";
	TableHeader();

	for (const sClient& Client : vClients)
	{
		PrintClientCard(Client);
		cout << endl;
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}

int main()
{
	vector<sClient> vClients = GetClients();
	PrintAllClientsData(vClients);

	return 0;
}