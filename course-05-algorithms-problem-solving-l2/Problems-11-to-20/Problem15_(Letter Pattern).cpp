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

void PrintLetterPattern(int Number)
{
   cout << "\n";

    // for(int i = 65 ; i< Number + 65; i++)
    // {
    //     for(int j = 65; j <= i; j++)
    //     {
    //        cout << char(i); 
    //     }
    //     cout << "\n";
    // }

    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char (i);
        }
        cout << "\n";   
    }
}

int main()
{
   PrintLetterPattern(ReadPositiveNumber("Please enter a positive number :"));
    
   return 0;
}