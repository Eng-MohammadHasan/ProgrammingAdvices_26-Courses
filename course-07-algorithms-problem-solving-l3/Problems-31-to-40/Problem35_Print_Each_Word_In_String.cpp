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

void PrintEachWordInString(string S1)
{
	char Space = ' ';
	string temp = "";

	char Start = S1[0];

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == ' ')
		{
			if (!temp.empty())
			{
				cout << temp << endl;
				temp = "";
			}
		}
		else
		{
			temp += S1[i];
		}
	}

	// Print the last word if it exists
	if (!temp.empty())
		cout << temp << endl;
}

int main()
{

	PrintEachWordInString(ReadString());

	system("pause>0");
}
