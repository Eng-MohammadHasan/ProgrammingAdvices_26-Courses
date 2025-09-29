#include <iostream>
#include <string>

using namespace std;

int main()
{

	string S1 = "My Name is Mohammad Hasan Abdelqader";
	string S2;

	cout << "\n*********************************\n";

	cout << "S1 : " + S1 << endl << endl;
	for (int i = 0; i < S1.length(); i++)
	{
		S2 += S1.at(i);
	}


	cout << "S2 : " + S2 << endl << endl;

	cout << "\n*********************************\n";

	for (int i = S1.length(); i >= 0; i--)
	{
		S1 = S1.insert(i, "*");
	}
	cout << "S1 After Modification : " << S1 << "\n\n";

	cout << "\n*********************************\n";

	S2.clear();

	for (const char& c : S1)
	{
		S2.push_back('*');
		S2.push_back(c);
	}

	cout << "S2 After Modification : " << S2 << "\n\n";

	cout << "\n*****************************************\n\n";

	cout << "Find Text (\"Mohammad\") in The String : \n";
	cout << S1.find("  Mohammad") << endl;
	cout << S1.find(" Mohammad") << endl;
	cout << S1.find("Mohammad") << endl;

	cout << "\nFind Text (\"mohammad\") in The String : ";
	cout << S1.find("mohammad") << endl;

	cout << "\nFind Text (\"mohammad\") in The String : ";
	if (S1.find("mohammad") == S1.npos)
	{
		cout << "mohammad Not Found. " << endl;
	}
	if (S1.find("mohammad") == string::npos)
	{
		cout << "mohammad Not Found. " << endl;
	}
	cout << "\n*****************************************\n";
	cout << "\n*****************************************\n\n";

    
	S2.clear();
	// or 
	// // means: “keep running the loop as long as S2 has characters”
	// S2.length() > 0 → loop runs
	// S2.length() = 0 → loop stops
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// anything not zero is true, so the loop runs while S2 has characters
	// when S2.length() becomes 0, it gives false and stops the loop
	
    while (S2.length()) {
		S2.pop_back();
	}


	return 0;
}
