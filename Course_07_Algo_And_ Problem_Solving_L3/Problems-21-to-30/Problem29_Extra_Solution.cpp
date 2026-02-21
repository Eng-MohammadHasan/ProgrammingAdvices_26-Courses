#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, Punctuation = 2, Digit = 3, All = 4 };

string ReadString()
{
    string S1;

    cout << "Please Enter Your String?\n";
    getline(cin, S1);

    return S1;
}

//better version for the upper function 
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    short Counter = 0;

    for (char ch : S1) {
        switch (WhatToCount)
        {
        case enWhatToCount::CapitalLetters: if (isupper(ch)) Counter++; break;
        case enWhatToCount::SmallLetters: if (islower(ch)) Counter++; break;
        case enWhatToCount::Punctuation: if (ispunct(ch)) Counter++; break;
        case enWhatToCount::Digit: if (isdigit(ch)) Counter++; break;
        case enWhatToCount::All: Counter++; break;
        }
    }

    return Counter;
}

short CountCapitalLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

short CountSmallLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

short CountPunctuationLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (ispunct(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

short CountDigitLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isdigit(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{

    string S1 = ReadString();

    cout << "\nString Length = " << S1.length();
    cout << "\nCapital Letters Count = " << CountCapitalLetters(S1);
    cout << "\nSmall Letters Count = " << CountSmallLetters(S1);


    //using the generic function 
    cout << "\n\nMethod 2\n";
    cout << "\nString Length = " << CountLetters(S1);
    cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count = " << CountLetters(S1, enWhatToCount::SmallLetters);
    cout << "\nPunctuation Letters Count = " << CountLetters(S1, enWhatToCount::Punctuation);
    cout << "\nDigit Letters Count = " << CountLetters(S1, enWhatToCount::Digit);
    cout << "\nAll Letters Count = " << CountLetters(S1); // WhatToCount = All by default  

    system("pause>0");
}

//Generic function
/*short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
        {
            Counter++;
        }

        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}
*/

// Generic function: count letters in a string based on type
// If WhatToCount == All, we return the string length directly without looping

/*
short CountLetters(const string& S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    // If counting all letters, no need to loop
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    short Counter = 0;

    // Loop once and count only the type requested
    if (WhatToCount == enWhatToCount::CapitalLetters)
    {
        for (char ch : S1)
            if (isupper(ch)) Counter++;
    }
    else if (WhatToCount == enWhatToCount::SmallLetters)
    {
        for (char ch : S1)
            if (islower(ch)) Counter++;
    }

    return Counter;
}
*/
