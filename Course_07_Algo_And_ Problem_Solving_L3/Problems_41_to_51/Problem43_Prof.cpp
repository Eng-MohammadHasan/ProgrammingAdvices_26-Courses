#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

vector <string> SplitString(string S1, string delimiter)
{
	vector <string> Tokens;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(delimiter)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			Tokens.push_back(sWord);
		}

		S1.erase(0, pos + delimiter.length());
	}

	if (!S1.empty())
	{
		Tokens.push_back(S1);
	}

	return Tokens;
}

string JoinString(vector <string>& vString, string Delimiter)
{
	string S1;

	for (string& s : vString)
	{
		S1 = S1 + s + Delimiter;
	}

	return S1.substr(0, S1.length() - Delimiter.length());
}

string LowerAllString(string S1)
{
	for (char& ch : S1)
	{
		ch = (char)(tolower(ch));
	}

	return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
{
	vector <string> vString = SplitString(S1, " ");

	for (string& word : vString)
	{
		if (MatchCase)
		{
			if (word == StringToReplace)
			{
				word = sReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(word) == LowerAllString(StringToReplace))
			{
				word = sReplaceTo;
			}
		}

		return JoinString(vString, " ");
	}
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal String\n" << S1;

	cout << "\n\nReplace with match case:\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo) << endl;

	cout << "\n\nReplace with don't match case:\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;
	cout << endl;

	system("pause");
}
