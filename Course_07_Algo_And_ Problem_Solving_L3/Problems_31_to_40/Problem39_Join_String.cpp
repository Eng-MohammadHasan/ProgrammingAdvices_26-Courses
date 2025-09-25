#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(const vector <string>& vString, string Delimiter)
{
	string S1 = "";

	for (const string& Word : vString)
	{
		S1 += Word;

		if (Word != vString.back())
		{
			S1 += Delimiter;
		}
	}

	/*
		short Size = vTokens.size();
		for(short i = 0 ; i< Size ; i++)
		{
			Text += (i != Size -1) ? vTokens.at(i) + Delimiter : vTokens.at(i);
		}

		return Text;
	*/
	return S1;
}

int main()
{
	vector <string> vString = { "Mohammad" , "Faid" , "Ali" , "Maher" };

	cout << "\nVector after join:\n";
	cout << JoinString(vString, " ") << endl;

	system("pause>0");
}
