// <cctype> functions in C++
// Character classification:
//   isalnum(c)  -> alphanumeric? (letter or digit)
//   isalpha(c)  -> alphabetic? (A-Z or a-z)
//   isdigit(c)  -> digit? (0-9)
//   isxdigit(c) -> hexadecimal digit? (0-9, A-F, a-f)
//   islower(c)  -> lowercase letter?
//   isupper(c)  -> uppercase letter?
//   isspace(c)  -> whitespace? (space, tab, newline, etc.)
//   ispunct(c)  -> punctuation? (printable but not alnum or space)
//   isprint(c)  -> printable? (any visible char including space)
//   isgraph(c)  -> visible (printable but not space)
//   iscntrl(c)  -> control character? (e.g., \n, \t)
//
// Character conversion:
//   tolower(c)  -> convert to lowercase
//   toupper(c)  -> convert to uppercase

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = 'z';
    char d = '5';
    char h = '\n';
    char s = ' ';
    char p = '!';

    cout << boolalpha; // print true/false instead of 1/0

    cout << "isalnum('A') = " << isalnum(a) << endl;   // true
    cout << "isalpha('z') = " << isalpha(b) << endl;   // true
    cout << "isdigit('5') = " << isdigit(d) << endl;   // true
    cout << "isxdigit('F') = " << isxdigit('F') << endl; // true
    cout << "islower('z') = " << islower(b) << endl;   // true
    cout << "isupper('A') = " << isupper(a) << endl;   // true
    cout << "isspace(' ') = " << isspace(s) << endl;   // true
    cout << "ispunct('!') = " << ispunct(p) << endl;   // true
    cout << "isprint('A') = " << isprint(a) << endl;   // true
    cout << "isgraph('A') = " << isgraph(a) << endl;   // true
    cout << "iscntrl('\\n') = " << iscntrl(h) << endl; // true

    cout << "tolower('A') = " << char(tolower(a)) << endl; // a
    cout << "toupper('z') = " << char(toupper(b)) << endl; // Z

    return 0;
}

/*
Expected Output (example):
isalnum('A') = true
isalpha('z') = true
isdigit('5') = true
isxdigit('F') = true
islower('z') = true
isupper('A') = true
isspace(' ') = true
ispunct('!') = true
isprint('A') = true
isgraph('A') = true
iscntrl('\n') = true
tolower('A') = a
toupper('z') = Z
*/
