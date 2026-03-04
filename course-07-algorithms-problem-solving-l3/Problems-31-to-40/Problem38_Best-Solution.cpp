#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string TrimLeft(string S1) {
	for (size_t i = 0; i < S1.length(); i++) {
		if (!isspace(static_cast<unsigned char>(S1[i]))) {
			return S1.substr(i);
		}
	}
	return "";
}

string TrimRight(string S1) {
	for (int i = S1.length() - 1; i >= 0; i--) {
		if (!isspace(static_cast<unsigned char>(S1[i]))) {
			return S1.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string S1) {
	return TrimLeft(TrimRight(S1));
}

int main()
{
	string S1 = "	 Mohammad Abu-Hadhoud	  ";

	cout << "\nString     = " << S1;
	cout << "\n\nTrim Left  = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim       = " << Trim(S1);

	system("pause>0");
}