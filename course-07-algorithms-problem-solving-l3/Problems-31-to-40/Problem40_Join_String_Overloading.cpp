#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(const vector <string>& vString, string Delimiter)
{
	string S1 = "";

	for (const string& Word : vString)
	{
		S1 = S1 + Word + Delimiter;
	}

	return S1.substr(0, S1.length() - Delimiter.length());
}

string JoinString(string arrString[], short Length, string Delimiter)
{
	string Text = "";

	for (short i = 0; i < Length; i++)
	{
		Text = Text + arrString[i] + Delimiter;
	}

	return Text.substr(0, Text.length() - Delimiter.length());
}

int main()
{
	vector <string> vString = { "Mohammad" , "Faid" , "Ali" , "Maher" };
	string arrString[] = { "Mohammad" , "Faid" , "Ali" , "Maher" };

	cout << "\nVector after join: \n";
	cout << JoinString(vString, " ") << endl;

	cout << "\n\nArray after join: \n";
	cout << JoinString(arrString, 4, " ") << endl;

	system("pause>0");
}
