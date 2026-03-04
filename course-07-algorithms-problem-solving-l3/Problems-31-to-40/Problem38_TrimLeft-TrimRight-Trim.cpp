#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum enTrimType { TrimLeftOp = 1, TrimRightOp = 2, TrimOp = 3 };

enTrimType ReadTrimType() {
	cout << "\nPlease Enter Trim Type you prefer:\n";
	cout << "-----------------------------\n";
	cout << "| (1) Trim Left Operation   |\n";
	cout << "| (2) Trim Right Operation  |\n";
	cout << "| (3) Trim Operation        |\n";
	cout << "-----------------------------\n";

	short TrimType;
	cin >> TrimType;
	return (enTrimType)TrimType;
}

string TrimLeft(string S1) {
	while (!S1.empty() && (S1.front() == ' ' || S1.front() == '\t'))
		S1.erase(0, 1);
	return S1;
}

string TrimRight(string S1) {
	while (!S1.empty() && (S1.back() == ' ' || S1.back() == '\t'))
		S1.pop_back();
	return S1;
}

string Trim(string S1) {
	return TrimLeft(TrimRight(S1));
}

void PerformTrim(enTrimType type, string S1) {
	switch (type) {
	case TrimLeftOp:
		cout << "\nTrim Left  = [" << TrimLeft(S1) << "]\n";
		break;
	case TrimRightOp:
		cout << "\nTrim Right = [" << TrimRight(S1) << "]\n";
		break;
	case TrimOp:
		cout << "\nTrim       = [" << Trim(S1) << "]\n";
		break;
	default:
		cout << "Invalid Choice\n";
		break;
	}
}

int main() {
	string S1 = "\t Mohammad Abu-Hadhoud   ";
	cout << "\nOriginal String = [" << S1 << "]\n";

	enTrimType choice = ReadTrimType();
	PerformTrim(choice, S1);

	system("pause>0");
	return 0;
}
