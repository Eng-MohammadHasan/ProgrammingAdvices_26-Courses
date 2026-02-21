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

char InvertLetterCase(char char1)
{
    return isupper(char1) ? (char)tolower(char1) : (char)toupper(char1); // I did explicit casting 
}

int main()
{
    char Ch1 = ReadCharacter();
    cout << "\nChar after inverting case:\n";
    Ch1 = InvertLetterCase(Ch1);
    cout << Ch1 << endl;

    system("pause>0");
}
