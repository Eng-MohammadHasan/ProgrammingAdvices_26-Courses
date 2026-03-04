#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
    int Number = 0;

    do
    {
        cout << message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void FillLetterArray(char Letters[26] , int size)
{
    for (int i = 0; i < size; i++)
    {
        Letters[i] = char(i + 65); // A = 65 :)
    }
}

void PrintLetterPattern(int Number)
{
   if(Number > 26)
   {
    Number = 26; // Capacity to 26 , to prevent out-of-bounds access :)
   }
   
    char Letters[26];
    FillLetterArray(Letters , Number);

    cout << "\n";

    for(int i = 0; i < Number; i++)
    {
        for (int j =0 ; j <= i; j++)
        {
            cout << Letters[i] ;
        }
        cout << "\n";
    }

}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please Enter a positive number :"));
    return 0;
}