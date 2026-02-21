#include <iostream>
#include <string>

using namespace std;

string ReadInfo()
{
    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

void PrintFirstLetterOfEachWord(string S1)
{
    char space = ' ';

    cout << "\nFirst letters of this string:\n";
    cout << S1[0] << endl;

    for (short i = 1; i < S1.length(); i++)
    {
        if (S1.at(i) == ' ')
        {
            cout << S1.at(i + 1) << endl;
        }
    }
}

int main()
{

    PrintFirstLetterOfEachWord(ReadInfo());

    system("pause>0");
}
