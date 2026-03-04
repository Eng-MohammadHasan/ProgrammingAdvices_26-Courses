#include <iostream>
#include <vector>
#include <string>

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

	if (S1 != "")
	{
		Tokens.push_back(S1); // it adds last word of the string
	}

	return Tokens;
}

string ReverseWordsInString(string S1)
{
	vector <string> vString;
	string S2 = "";

	vString = SplitString(S1, " ");

	//declare iterator
	vector <string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		S2 += *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1); //remove last space. 

	return S2;
}

int main()
{
	string S1 = ReadString();
	cout << "\n\nString after reversing words : ";
	cout << '\n' << ReverseWordsInString(S1) << endl;

	system("pause");
}
		