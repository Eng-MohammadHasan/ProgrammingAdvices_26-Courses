#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>

using namespace std;

string ReplaceWordsWithMatchCase(string S1, string StringToReplace, string sReplaceTo)
{
	size_t pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.erase(pos, StringToReplace.length());
		S1 = S1.insert(pos, sReplaceTo);

		pos = S1.find(StringToReplace);
	}

	return S1;
}

string LowerAllString(string S1)
{

	for (char& ch : S1)
	{
		ch = (char)tolower(ch);
	}

	return S1;
}

string ReplaceWordsWithoutMatchCase(string S1, string StringToReplace, string sReplaceTo)
{
	string S1_Lower = LowerAllString(S1);
	string StringToReplace_Lower = LowerAllString(StringToReplace);

	size_t pos = S1_Lower.find(StringToReplace_Lower);

	while (pos != std::string::npos)
	{
		S1 = S1.erase(pos, StringToReplace.length());
		S1 = S1.insert(pos, sReplaceTo);

		S1_Lower = S1_Lower.erase(pos, StringToReplace.length());
		S1_Lower = S1_Lower.insert(pos, sReplaceTo);

		//prevents re-finding or looping over replaced parts , it could get stuck re-finding “jordan” repeatedly in the replaced part (infinite loop)!
		pos = S1_Lower.find(StringToReplace_Lower, pos + sReplaceTo.length());
	}

	return S1;
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

	system("pause>0");
}
