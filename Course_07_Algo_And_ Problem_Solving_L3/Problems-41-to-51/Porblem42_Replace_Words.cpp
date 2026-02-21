#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your string? \n";
	getline(cin, S1);

	return S1;
}

vector <string> SplitString(string S1, string delimiter)
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(delimiter)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + delimiter.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string
	}

	return vString;
}

string ReplaceWords(string S1 , string StringToReplace , string sReplaceTo)
{
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
	string S1 = ReadString();

	cout << "\nOrginal String : \n";
	cout << S1 << endl;

	cout << "\nString After Replace : \n";
	cout << ReplaceWords(S1, "Jordan", "USA");

	system("pause>0");
}
