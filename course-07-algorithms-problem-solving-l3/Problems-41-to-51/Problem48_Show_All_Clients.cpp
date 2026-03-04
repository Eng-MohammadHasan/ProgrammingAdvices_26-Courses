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

	short pos = 0;
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

sClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	sClient Client;
	vector <string> vClientData;

	vClientData = SplitString(Line, Separator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

vector<string> LoadClientsDataFromFile(string FileName)
{
	vector<string> vClientsInFile;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		//cout << "Client List (" << ") Client(s).\n";

		string Line;

		while (getline(MyFile, Line))
		{
			vClientsInFile.push_back(Line);
		}

		MyFile.close();
	}

	return vClientsInFile;
}

void TableHeader()
{
	cout << "\n_____________________________________________________________\n";
	cout << left << setw(15) << "| Account Number ";
	cout << setw(12) << "| Pin Code ";
	cout << setw(30) << "| Client Name ";
	cout << setw(15) << "| Phone ";
	cout << setw(12) << "| Balance ";
	cout << "\n_____________________________________________________________\n";
}

void ShowClient(const string Line)
{
	sClient Client;
	Client = ConvertLineToRecord(Line);

	cout << "| " << setw(15) << Client.AccountNumber;
	cout << "| " << setw(12) << Client.PinCode;
	cout << "| " << setw(30) << Client.Name;
	cout << "| " << setw(15) << Client.Phone;
	cout << "| " << setw(12) << Client.AccountBalance;
	cout << "\n";
}

void ShowClients()
{
	vector<string> vClientsRecords;
	vClientsRecords = LoadClientsDataFromFile(ClientsFileName);

	cout << "Client List ( " << vClientsRecords.size() << " ) Client(s).";
	TableHeader();

	for (const string& Line : vClientsRecords)
	{
		ShowClient(Line);
	}

	cout << "\n\n_____________________________________________________________\n";

}

int main()
{
	ShowClients();

	system("pause>0");

	return 0;
}
