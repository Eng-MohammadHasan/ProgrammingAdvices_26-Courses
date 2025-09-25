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
	string delimiter = " ";

	cout << "\nYour string words are : \n\n";
	short pos = 0;
	string sWord; // define a string variable , this var I'll use it to store each word and print it.

	// Use find() function to get the position of the delimiters
	while ((pos = S1.find(delimiter)) != string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "") // here maybe the delimiter(space) ... we got 3 spaces at first so here we make sure , if we got the space at first then it's substr(0,0) , so here it will keep erasing the spaces till we got a word :)! 
		{
			cout << sWord << endl;
		}

		// erase() until position and move to next word,
		//sometimes delimiter (more than a normal space)
		S1.erase(0, pos + delimiter.length());
	}

	if (S1 != "")
	{
		cout << S1 << endl; //it prints last word of the string , (the only word).
	}
}

int main()
{

	PrintEachWordInString(ReadString());

	system("pause>0");
}
