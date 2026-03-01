#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();

enum enMainMenuOptions
{
	eShowClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6,
	eExit = 7
};

enum enTransactionsMenuOptions
{
	eDeposit = 1, eWithdraw = 2,
	eTotalBalances = 3, eMainMenu = 4
};

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false; //flag
};

unsigned short ReadNumberInRange(unsigned short From, unsigned short To)
{
	unsigned short Number = 0;
	cin >> Number;

	while (cin.fail() || (Number < From || Number > To))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Input, Enter a valid one : " << endl;

		cin >> Number;
	}

	return Number;
}

vector<string> SplitString(string S1, string Delimiter)
{
	vector<string> vString;

	size_t  pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delimiter)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delimiter.length());
	}

	if (!S1.empty())
	{
		vString.push_back(S1); // it adds the last word of the string.
	}

	return vString;
}

sClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Separator);

	if (vClientData.size() >= 5)
	{
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];

		// Protect against invalid numeric text in file
		// (stod throws exception if conversion fails)
		try
		{
			Client.AccountBalance = stod(vClientData[4]);
		}
		catch (...)
		{
			Client.AccountBalance = 0;
		}
	}

	return Client;
}

string ConvertRecordToLine(const sClient& ClientData, string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += ClientData.AccountNumber + Separator;
	stClientRecord += ClientData.PinCode + Separator;
	stClientRecord += ClientData.Name + Separator;
	stClientRecord += ClientData.Phone + Separator;
	stClientRecord += to_string(ClientData.AccountBalance);

	return stClientRecord;
}

vector <sClient> LoadClientsDataFromFile(const string& FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // read Mode

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

void PrintClientListHeader()
{
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number ";
	cout << "| " << left << setw(10) << "Pin Code ";
	cout << "| " << left << setw(40) << "Client Name ";
	cout << "| " << left << setw(12) << "Phone ";
	cout << "| " << left << setw(12) << "Balance ";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientRecordLine(const sClient& Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List ( " << vClients.size() << " ) Client(s).";
	PrintClientListHeader();

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Available In the System!";
	}
	else
	{
		for (const sClient& Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();
}

enMainMenuOptions ReadMainMenuOption()
{
	unsigned short OptionNumber;
	cout << "Choose what do you want to do? [1 to 7]? ";
	OptionNumber = ReadNumberInRange(1, 7);

	return (enMainMenuOptions)OptionNumber;
}

bool ClientExistByAccountNumber(const string& AccountNumber, const vector<sClient>& vClients)
{
	for (const sClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			return true;
		}
	}

	return false;
}

sClient ReadNewClientData()
{
	vector<sClient> vClients;
	vClients = LoadClientsDataFromFile(ClientsFileName);

	sClient Client;

	cout << "\nEnter Account Number? ";
	// Usage of std::ws will extract all the whitespaces character
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistByAccountNumber(Client.AccountNumber, vClients))
	{
		cout << "\nClient with [" << Client.AccountNumber
			<< " already exists, Enter another Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void AddDataLineToFile(const string& FileName, const string& stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClientData();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char AddMore = 'n';

	do
	{
		//system("cls");
		cout << "Adding New Client : \n";

		AddNewClient();
		cout << "\n\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\t Add New Clients Screen ";
	cout << "\n-----------------------------------\n";

	AddNewClients();
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "Please Enter AccountNumber? ";
	cin >> AccountNumber;

	return AccountNumber;
}

void PrintClientCard(const sClient& Client)
{
	cout << "\n\nThe following are the client details: ";
	cout << "\n-----------------------------------------\n";

	cout << left;

	cout << setw(18) << "Account Number" << " : " << Client.AccountNumber;
	cout << "\n" << setw(18) << "Pin Code" << " : " << Client.PinCode;
	cout << "\n" << setw(18) << "Name" << " : " << Client.Name;
	cout << "\n" << setw(18) << "Phone" << " : " << Client.Phone;
	cout << "\n" << setw(18) << "Account Balance" << " : " << Client.AccountBalance;

	cout << "\n-----------------------------------------\n";
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

bool MarkClientForDeleteByAccountNumber(const string& AccountNumber, vector<sClient>& vClients)
{
	for (sClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

void SaveClientsDataToFile(const string& FileName, const vector<sClient>& vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (const sClient& Client : vClients)
		{
			if (Client.MarkForDelete == false)
			{
				// we only write records that are not marked as delete.
				DataLine = ConvertRecordToLine(Client);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}
}

bool DeleteClientByAccountNumber(const string& AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to delete this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!\n";
	}

	return false;
}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\t Delete Client Screen ";
	cout << "\n-----------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);
}

sClient ChangeClientRecord(const string& AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(const string& AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to update this client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& CurrentClient : vClients)
			{
				if (CurrentClient.AccountNumber == AccountNumber)
				{
					CurrentClient = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Succussfully.";
			return true;
		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!\n";
	}

	return false;
}

void ShowUpdateClientScreen()
{
	cout << "\n--------------------------------------\n";
	cout << "\t Update Client Info Screen ";
	cout << "\n--------------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\t Find Client Screen ";
	cout << "\n-----------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!\n";
	}
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------\n";
}

void GoBackToTransactionsMenuScreen()
{
	cout << "\n\nPress any key to go back to Transactions Menu...";
	system("pause>0");
	ShowTransactionsMenu();
}

enTransactionsMenuOptions ReadTransactionsMenuOption()
{
	unsigned short TransactionOptionNumber;

	cout << "\nChoose what do you want to do? [1 to 4]? ";
	TransactionOptionNumber = ReadNumberInRange(1, 4);

	return (enTransactionsMenuOptions)TransactionOptionNumber;
}

bool DepositToClientBalanceByAccountNumber(const string& AccountNumber, double DepositAmount, vector<sClient>& vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		for (sClient& CurrentClient : vClients)
		{
			if (CurrentClient.AccountNumber == AccountNumber)
			{
				CurrentClient.AccountBalance += DepositAmount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully. New balance is: "
					<< CurrentClient.AccountBalance << endl;

				return true;
			}
		}
	}

	return false;
}

void ShowDepositScreen()
{
	cout << "\n--------------------------------------\n";
	cout << "\t Deposit Screen ";
	cout << "\n--------------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber;
	sClient Client;

	AccountNumber = ReadClientAccountNumber();
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double DepositAmount;
	cout << "\n\nPlease enter deposit amount? \n";
	cin >> DepositAmount;

	DepositToClientBalanceByAccountNumber(AccountNumber, DepositAmount, vClients);
}

double CountTotalBalances(const vector<sClient>& vClients)
{
	double TotalBalances = 0.0;

	for (const sClient& Client : vClients)
	{
		TotalBalances += Client.AccountBalance;
	}

	return TotalBalances;
}

void ShowTotalBalancesScreen()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tBalances List ( " << vClients.size() << " ) Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number ";
	cout << "| " << left << setw(40) << "Client Name ";
	cout << "| " << left << setw(12) << "Balance ";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Available In the System!";
	}
	else
	{
		for (const sClient& Client : vClients)
		{
			cout << "| " << left << setw(15) << Client.AccountNumber;
			cout << "| " << left << setw(40) << Client.Name;
			cout << "| " << left << setw(12) << Client.AccountBalance;
			cout << endl;
		}
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = CountTotalBalances(vClients);
	cout << "\n\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
}

double ReadValidWithdrawAmount(double ClientAccountBalance)
{
	double WithdrawAmount;
	cout << "\n\nPlease enter withdraw amount? \n";
	cin >> WithdrawAmount;

	while (ClientAccountBalance < WithdrawAmount)
	{
		cout << "\n\nAmount Exceeds the balance, you can withdraw up to : "
			<< ClientAccountBalance;
		cout << "\nPlease enter another amount? ";
		cin >> WithdrawAmount;
	}

	return WithdrawAmount;
}

bool WithdrawToClientBalanceByAccountNumber(const string& AccountNumber, double WithdrawAmount, vector<sClient>& vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		for (sClient& CurrentClient : vClients)
		{
			if (CurrentClient.AccountNumber == AccountNumber)
			{
				CurrentClient.AccountBalance -= WithdrawAmount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully. New balance is: "
					<< CurrentClient.AccountBalance << endl;

				return true;
			}
		}
	}

	return false;
}

void ShowWithdrawScreen()
{
	cout << "\n--------------------------------------\n";
	cout << "\t Withdraw Screen ";
	cout << "\n--------------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber;
	sClient Client;

	AccountNumber = ReadClientAccountNumber();
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double WithdrawAmount = ReadValidWithdrawAmount(Client.AccountBalance);
	WithdrawToClientBalanceByAccountNumber(AccountNumber, WithdrawAmount, vClients);
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionOption)
{
	switch (TransactionOption)
	{
	case enTransactionsMenuOptions::eDeposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenuScreen();
		break;
	}
	case enTransactionsMenuOptions::eWithdraw:
	{
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenuScreen();
		break;
	}
	case enTransactionsMenuOptions::eTotalBalances:
	{
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenuScreen();
		break;
	}
	case enTransactionsMenuOptions::eMainMenu:
	{
		system("cls");
		ShowMainMenu();
		break;
	}

	}
}

void ShowTransactionsMenu()
{
	system("cls");

	cout << "====================================================\n";
	cout << "\t\tTransactions Menu Screen\n";
	cout << "====================================================\n";
	cout << "\t[1] Deposit. \n";
	cout << "\t[2] Withdraw. \n";
	cout << "\t[3] Total Balances. \n";
	cout << "\t[4] Main Menu. \n";
	cout << "====================================================\n";

	enTransactionsMenuOptions TransactionOption;
	TransactionOption = ReadTransactionsMenuOption();

	PerformTransactionsMenuOption(TransactionOption);
}

void PerformChosenMainMenuOption(enMainMenuOptions MainMenuOption)
{
	switch (MainMenuOption)
	{
	case enMainMenuOptions::eShowClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eAddNewClient:
	{
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eDeleteClient:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eUpdateClient:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eFindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::eTransactions:
	{
		system("cls");
		ShowTransactionsMenu();
		break;
	}
	case enMainMenuOptions::eExit:
	{
		system("cls");
		ShowEndScreen();
		break;
	}

	}
}

void PrintMainMenuScreen()
{
	cout << "====================================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "====================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "====================================================\n";
}

void ShowMainMenu()
{
	system("cls");
	PrintMainMenuScreen();

	enMainMenuOptions MenuOption = ReadMainMenuOption();
	PerformChosenMainMenuOption(MenuOption);
}

int main()
{
	ShowMainMenu();

	system("pause>0");
	return 0;
}