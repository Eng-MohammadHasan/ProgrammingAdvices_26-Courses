#include <iostream>

using namespace std;

void PrintFibonacciSeriesUsingLoop(short Number)
{
    int Previous2 = 0, Previous1 = 1;
    int FibNumber = 0;

    cout << Previous1 << '\t';

    for (short i = 2; i <= Number; i++)
    {
        FibNumber = Previous2 + Previous1;
        cout << FibNumber << '\t';

        Previous2 = Previous1;
        Previous1 = FibNumber;
    }
}

int main()
{

    PrintFibonacciSeriesUsingLoop(10);

    system("pause>0");
}
