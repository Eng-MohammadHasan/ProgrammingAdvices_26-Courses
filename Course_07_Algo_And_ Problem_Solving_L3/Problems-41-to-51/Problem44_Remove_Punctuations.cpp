#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string RemovePunctuations(string S1)
{
	short pos;

	for (short i = 0; i < S1.length(); i++)
	{
		if (ispunct(S1[i]))
		{
			S1 = S1.erase(i, 1);
			i--;
		}
	}

	return S1;
}

int main()
{
	string S1 = "Welcome ><<????,,to<< Jordan, Jordan is a nice country: it's amazing.";

	cout << "\nOriginal String\n" << S1;

	cout << "\n\nPunctuations Removed:\n";
	cout << RemovePunctuations(S1) << endl;
	cout << endl;

	system("pause");
}
