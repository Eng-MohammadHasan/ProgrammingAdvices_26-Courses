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

int main()
{
	vector <string> vString = { "Mohammad" , "Faid" , "Ali" , "Maher" };

	cout << "\nVector after join:\n";
	cout << JoinString(vString, " ") << endl;

	system("pause>0");
}
