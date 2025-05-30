#include <iostream>
#include <string>

using namespace std;

void PrintWordsFromAAAToZZZ()
{
    cout << "\n";
    string word = "";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                // Append the current letter for the first position.
                // word.append(1, char(i));
                
                // Append the current letter for the second position.
                // word.append(1, char(j));
                
                // Append the current letter for the third position.
                // word.append(1, char(k));

                cout << word << endl;

                word = "";
            }
        }
        cout << "\n---------------------\n";
    }
}

int main()
{
    PrintWordsFromAAAToZZZ();
    return 0;
}