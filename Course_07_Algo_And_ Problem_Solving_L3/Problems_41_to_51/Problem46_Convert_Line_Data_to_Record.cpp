#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

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

void PrintClientCard(const sClient& Client)
{
	cout << "\n\nThe following is the extracted client record : \n";

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

int main()
{
	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

	cout << "\nLine Record is : \n";
	cout << stLine;

	sClient Client = ConvertLineToRecord(stLine);
	PrintClientCard(Client);

	system("pause>0");

	return 0;
}

