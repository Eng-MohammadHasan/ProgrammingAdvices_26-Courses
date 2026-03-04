#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct stPasswordDetails
{
	string Password;
	short NumberOfUpperCase = 0;
	short NumberOfLowerCase = 0;
	short NumberOfDigits = 0;
	short NumberOfPunctuation = 0;
	bool IsStrongPassword;
};

string ReadPassword()
{
	string Password;

	cout << "Please Enter a password : \n";
	getline(cin, Password);

	return Password;
}

void CountUpperCase(stPasswordDetails& PasswordDetails)
{
	short& UpperCase = PasswordDetails.NumberOfUpperCase;
	string Password = PasswordDetails.Password;

	for (int i = 0; i < Password.length(); i++)
	{
		if (isupper(Password.at(i)))
		{
			UpperCase++;
		}
	}
}

void CountLowerCase(stPasswordDetails& PasswordDetails)
{
	short& LowerCase = PasswordDetails.NumberOfLowerCase;
	string Password = PasswordDetails.Password;

	for (int i = 0; i < Password.length(); i++)
	{
		if (islower(Password.at(i)))
		{
			LowerCase++;
		}
	}
}

void CountDigits(stPasswordDetails& PasswordDetails)
{
	short& Digits = PasswordDetails.NumberOfDigits;
	string Password = PasswordDetails.Password;

	for (int i = 0; i < Password.length(); i++)
	{
		if (isdigit(Password.at(i)))
		{
			Digits++;
		}
	}
}

void CountPunctuation(stPasswordDetails& PasswordDetails)
{
	short& Punctuation = PasswordDetails.NumberOfPunctuation;
	string Password = PasswordDetails.Password;

	for (int i = 0; i < Password.length(); i++)
	{
		if (ispunct(Password.at(i)))
		{
			Punctuation++;
		}
	}
}

void IsStrongPassword(stPasswordDetails& PasswordDetails)
{
	if (PasswordDetails.NumberOfUpperCase > 0 && PasswordDetails.NumberOfLowerCase > 0 && PasswordDetails.NumberOfDigits > 0 && PasswordDetails.NumberOfPunctuation > 0 && PasswordDetails.Password.length() >= 8)
	{
		PasswordDetails.IsStrongPassword = true;
	}
	else
	{
		PasswordDetails.IsStrongPassword = false;
	}
}

void CallFunctionsToGetResults(stPasswordDetails& PasswordDetails)
{
	CountUpperCase(PasswordDetails);
	CountLowerCase(PasswordDetails);
	CountDigits(PasswordDetails);
	CountPunctuation(PasswordDetails);
	IsStrongPassword(PasswordDetails);
}

void PrintResults(stPasswordDetails PasswordDetails)
{
	cout << "Number of Upper case = " << PasswordDetails.NumberOfUpperCase << endl;
	cout << "Number of Lower case = " << PasswordDetails.NumberOfLowerCase << endl;
	cout << "Number of Digits = " << PasswordDetails.NumberOfDigits << endl;
	cout << "Number of Punctuation = " << PasswordDetails.NumberOfPunctuation << endl;

	if (PasswordDetails.IsStrongPassword)
	{
		cout << "Strong Password" << endl;
	}
	else
	{
		cout << "Weak Password" << endl;
	}
}

int main()
{
	stPasswordDetails PasswordDetails;
	PasswordDetails.Password = ReadPassword();

	CallFunctionsToGetResults(PasswordDetails);
	PrintResults(PasswordDetails);

	return 0;
}
