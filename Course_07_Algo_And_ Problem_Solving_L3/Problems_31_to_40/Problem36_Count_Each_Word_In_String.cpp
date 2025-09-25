#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

short CountWordsInString(string S1)
{
	string delimiter = " ";
	short Counter = 0;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(delimiter)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, pos + delimiter.length());
	}

	if (S1 != "")
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nThe number of words in your string is : ";
	cout << CountWordsInString(S1);

	system("pause>0");
}
