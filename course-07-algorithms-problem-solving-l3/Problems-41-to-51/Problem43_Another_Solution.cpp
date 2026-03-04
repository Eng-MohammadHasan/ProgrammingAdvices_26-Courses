#include <iostream>
#include <vector>
#include <cctype>
#include <string>

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

string LowerAllString(string S1)
{
	for (char& ch : S1)
	{
		ch = (char)(tolower(ch));
	}

	return S1;
}

string ReplaceWordsWithMatchCase(string S1, string StringToReplace, string sReplaceTo)
{
	vector <string> Tokens = SplitString(S1, " ");
	string S2 = "";

	for (string& word : Tokens)
	{
		if (word == StringToReplace)
		{
			word = sReplaceTo;
		}

		S2 += word + " ";
	}

	S2 = S2.substr(0, S2.length() - 1);

	return S2;

}

string ReplaceWordsWithoutMatchCase(string S1, string StringToReplace, string sReplaceTo)
{
	StringToReplace = LowerAllString(StringToReplace);
	S1 = LowerAllString(S1);

	vector <string> Tokens;
	string S2 = "";

	Tokens = SplitString(S1, " ");

	for (string& word : Tokens)
	{
		if (word == StringToReplace)
		{
			word = sReplaceTo;
		}

		S2 += word + " ";
	}

	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal String\n" << S1;

	cout << "\n\nReplace with match case:\n";
	cout << ReplaceWordsWithMatchCase(S1, StringToReplace, ReplaceTo) << endl;

	cout << "\n\nReplace with don't match case:\n";
	cout << ReplaceWordsWithoutMatchCase(S1, StringToReplace, ReplaceTo) << endl;
	cout << endl;

	system("pause");
}
