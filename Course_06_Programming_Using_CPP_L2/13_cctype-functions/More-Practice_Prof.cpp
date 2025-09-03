#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct stPasswordStatus
{
	short Upper = 0;
	short Lower = 0;
	short digit = 0;
	short symbol = 0;
};

string ReadPassword()
{
	string Password;

	cout << "Please Enter a password : \n";
	getline(cin, Password);

	return Password;
}

stPasswordStatus analyzePassword(const string& Password)
{
	stPasswordStatus PasswordStatus;

	for (const char& ch : Password)
	{
		if (isupper(ch))
			PasswordStatus.Upper++;
		else if (islower(ch))
			PasswordStatus.Lower++;
		else if (isdigit(ch))
			PasswordStatus.digit++;
		else if (ispunct(ch))
			PasswordStatus.symbol++;
	}

	return PasswordStatus;
}

bool isStrong(const string& Password, const stPasswordStatus& Status)
{
	return Password.length() >= 8 &&
		Status.Upper > 0 &&
		Status.Lower > 0 &&
		Status.digit > 0 &&
		Status.symbol > 0;
}

int main()
{
	string Password = ReadPassword();
	stPasswordStatus PasswordStatus = analyzePassword(Password);

	cout << "Uppercase: " << PasswordStatus.Upper << endl;
	cout << "Lowercase: " << PasswordStatus.Lower << endl;
	cout << "Digits: " << PasswordStatus.digit << endl;
	cout << "Symbols: " << PasswordStatus.symbol << endl;

	if (isStrong(Password, PasswordStatus))
		cout << "Strong Password" << endl;
	else
		cout << "Weak Password" << endl;

	return 0;
}
