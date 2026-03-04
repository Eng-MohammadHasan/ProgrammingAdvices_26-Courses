#include <iostream>
#include <iomanip> // this library stores std::setw
using namespace std;

void MultiplicationTableInMatrix(int Matrix[10][10])
{
    for(int Row = 0 ; Row < 10 ; Row++)
    {
        for(int Col = 0 ; Col < 10 ; Col++)
        {
           Matrix[Row][Col] = (Row + 1) * (Col + 1);
        }
        cout << endl;
    }
}

void PrintMatrix(int Matrix[10][10])
{
     for(int Row = 0 ; Row < 10 ; Row++)
    {
        for(int Col = 0 ; Col < 10; Col++)
        {
            printf("%02d\t", Matrix[Row][Col]);
        }
        cout << endl;
    }
}

int main()
{
    int Matrix[10][10];
    
    MultiplicationTableInMatrix(Matrix);
    PrintMatrix(Matrix);

    return 0;
}
