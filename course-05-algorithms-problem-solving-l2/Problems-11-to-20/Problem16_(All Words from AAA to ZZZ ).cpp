#include <iostream>
using namespace std;

void PrintAllWordsAAAToZZZ()
{
    cout << "\n";

    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int k = 1; k <=26 ; k++)
            {
                cout << char(64 + i) << char(64 + j) << char(64 + k);
                cout << endl;
            }
        }
        cout << "\n";
    }
}

int main()
{
    PrintAllWordsAAAToZZZ();
    return 0;
}