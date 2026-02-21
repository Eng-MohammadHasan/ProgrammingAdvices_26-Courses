#include <iostream>
#include <cctype>

using namespace std;

char ReadCharacter()
{
    char Character;

    cout << "Please Enter a Character?\n";
    cin >> Character;

    return Character;
}

char InvertCharacter(char Character)
{
    short  DifferenceValue = 32;
    int c;

    if (isupper(Character))
    {
        c = (int)Character;
        c += DifferenceValue;
    }
    else
    {
        c = (int)Character;
        c -= DifferenceValue;
    }

    return char(c);
}

void PrintInvertedCharacter(char c)
{
    cout << "\nChar after inverting case:\n";
    cout << c << endl;
}

int main()
{

    PrintInvertedCharacter(InvertCharacter(ReadCharacter()));

    system("pause>0");
}
