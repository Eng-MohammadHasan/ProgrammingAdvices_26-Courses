#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Built in Functions (Methods)

	string S1 = "My Name is Mohammad Abu-Hadhoud, I love programming.";

	//Prints the length of the string
	cout << S1.length() << endl;

	//Returns the letter at position 3 
	cout << S1.at(3) << endl;

	//Adds @ProgrammingAdvices to the end of string
	S1.append(" @ProgrammingAdvices");
	cout << S1 << endl;

	//insert Ali in position 7
	S1.insert(10, " Ali");
	cout << S1 << endl;

	//Prints all the next 8 letters from position 16.
	cout << S1.substr(16, 8) << endl;

	//Adds one character to the end of the string
	S1.push_back('X');
	cout << S1 << endl;

	//Removes one character from the end of the string
	S1.pop_back();
	cout << S1 << endl;

	//Finds Ali in the string
	cout << S1.find("Ali") << endl;

	//Finds ali in the string
	cout << S1.find("ali") << endl;

	if (S1.find("ali") == S1.npos)
	{
		cout << "ali isn't found";
	}
    // the correct way (Recommended) is  , because (string::npos) is constant static member , it's not a member of an object like S1--->
    if(S1.find("ali") == string::npos)
    {
        cout << "ali isn't found";
    }

	//clears all string letters.
	S1.clear();
	cout << S1 << endl;

    //Replace Method
    //          012345678910
    string s = "I like cats";
    s.replace(7, 4, "dogs");
    // 7 → start index
    // 4 → number of characters to replace
    // "dogs" → new string

    cout << s;  // Output: I like dogs

	return 0;
}
