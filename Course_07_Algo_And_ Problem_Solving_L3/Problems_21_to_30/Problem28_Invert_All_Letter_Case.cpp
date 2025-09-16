#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadString()
{
    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

char InvertLetterCase(char char1)
{
    return isupper(char1) ? (char)tolower(char1) : (char)toupper(char1);
}

string InvertAllStringLettersCase(string str1)
{
    for (short i = 0; i < str1.length(); i++)
    {
        str1[i] = InvertLetterCase(str1[i]);
    }

    return str1;
}

int main()
{
    string str1 = ReadString();
    cout << "\nString after inverting all letter case:\n";
    str1 = InvertAllStringLettersCase(str1);
    cout << str1 << endl;

    system("pause>0");
}


