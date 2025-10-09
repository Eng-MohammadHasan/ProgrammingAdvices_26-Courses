#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{

		if (S1[i] != ' ') // we iterate till we get a letter, then we sub from the first letter till the end 
		{
			return S1.substr(i, S1.length() - i);
			// return S1.substr(i);
		}
	}

	return "";
}

string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}

	return "";
}

string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));
}

string ReadString()
{
	string S1;

	cout << "Please Enter your String ?\n";
	getline(cin, S1);

	return S1;
}

string ReverseString(string S1)
{
	string ReversedText = "";
	char Space = ' ';

	S1 = Trim(S1);

	for (int i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] == Space)
		{
			ReversedText = ReversedText + S1.substr(i + 1) + " ";
			S1.erase(i, S1.length() - i);
		}
	}

	if (!S1.empty())
	{
		ReversedText += S1;
	}

	return ReversedText;
}

int main()
{
	cout << ReverseString(ReadString()) << endl;

	return 0;
}