#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

struct stBankClient
{
	std::string AccountNumber;
	std::string PinCode;
	std::string Name;
	std::string Phone;
	double AccountBalance;
};

// -------------------- Validation --------------------
double ReadValidBalance()
{
	double Balance;

	while (!(std::cin >> Balance))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid balance, enter a number: ";
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return Balance;
}

// -------------------- Input --------------------
stBankClient ReadNewClient()
{
	stBankClient Client;

	std::cout << "Enter Account Number? ";
	std::getline(std::cin, Client.AccountNumber);

	std::cout << "Enter PinCode? ";
	std::getline(std::cin, Client.PinCode);

	std::cout << "Enter Name? ";
	std::getline(std::cin, Client.Name);

	std::cout << "Enter Phone? ";
	std::getline(std::cin, Client.Phone);

	std::cout << "Enter Account Balance? ";
	Client.AccountBalance = ReadValidBalance();

	return Client;
}

// -------------------- Output --------------------
const int TableWidth = 104;

void PrintTableHeader(const std::string& Separator = "|")
{
	std::cout << "\nConvert Data To Line With Delimiters:\n\n";
	std::cout << std::string(TableWidth, '_') << '\n';

	std::cout << std::left
		<< std::setw(25) << "Account Number" << Separator
		<< std::setw(15) << "Pin Code" << Separator
		<< std::setw(30) << "Name" << Separator
		<< std::setw(15) << "Phone" << Separator
		<< std::setw(15) << "Account Balance"
		<< '\n';

	std::cout << std::string(TableWidth, '_') << '\n';
}

void PrintClientRow(const stBankClient& Client, const std::string& Separator = "|")
{
	std::cout << std::left
		<< std::setw(25) << Client.AccountNumber << Separator
		<< std::setw(15) << Client.PinCode << Separator
		<< std::setw(30) << Client.Name << Separator
		<< std::setw(15) << Client.Phone << Separator
		<< std::setw(15) << std::fixed << std::setprecision(2) << Client.AccountBalance
		<< '\n';
}

// -------------------- Main --------------------
int main()
{
	stBankClient Client = ReadNewClient();

	PrintTableHeader();
	PrintClientRow(Client);

	return 0;
}
