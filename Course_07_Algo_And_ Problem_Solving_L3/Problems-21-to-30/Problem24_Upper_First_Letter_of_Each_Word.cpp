#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

//void UpperFirstLetterOfEachWord(string& S1)
//{
//    bool isFirstLetter = true; // flag to track the start of a word
//
//    for (short i = 0; i < S1.length(); i++)
//    {
//        if (S1[i] != ' ' && isFirstLetter)
//        {
//            S1[i] = toupper(S1[i]);
//        }
//
//        // set flag true only when the current character is a space
//        // so the next character (if not space) will be treated as the first letter
//        isFirstLetter = (S1[i] == ' ' ? true : false);
//    }
//}


// OR Another solution ....
string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true; // flag to track the start of a word

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        // set flag true only when the current character is a space
        // so the next character (if not space) will be treated as the first letter
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    cout << "\nString after conversion: \n";

    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;


    system("pause>0");
}
