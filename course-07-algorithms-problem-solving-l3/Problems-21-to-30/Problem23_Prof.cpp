#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true; // flag to track the start of a word

    cout << "\nFirst letters of this string: \n";

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }

        // set flag true only when the current character is a space
        // so the next character (if not space) will be treated as the first letter
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}

int main()
{

    PrintFirstLetterOfEachWord(ReadString());

    system("pause>0");
}
