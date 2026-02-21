#include <iostream>

using namespace std;

void PrintFibonacciUsingRecurssion(short Number, int Previous1, int Previous2)
{
    int FibNumber = 0;

    if (Number > 0)
    {
        FibNumber = Previous2 + Previous1;
        Previous2 = Previous1;
        Previous1 = FibNumber;
        cout << FibNumber << '\t';

        PrintFibonacciUsingRecurssion(Number - 1, Previous1, Previous2);
    }
}

int main()
{
    PrintFibonacciUsingRecurssion(2, 1, 0);

    system("pause>0");
}
