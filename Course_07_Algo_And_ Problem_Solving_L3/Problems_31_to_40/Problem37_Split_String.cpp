#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String?\n";
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

void PrintVector(const vector <string>& vString)
{
	cout << "\n";

	//ranged loop
	for (const string& Word : vString)
	{
		cout << Word << endl;
	}
}

int main()
{
	vector <string> vString;

	string S2 = "Mohammad,Ali,Ahmed,Mazen";
	string S3 = "Mohammad#,,#Ali#,,#Ahmed#,,#Mazen";

	vString = SplitString(ReadString(), " ");
	//vString = SplitString(S2, ",");
	//vString = SplitString(S3, "#,,#");

	cout << "\nTokens : " << vString.size() << endl;

	PrintVector(vString);

	system("pause>0");
}
