#include <iostream>
#include <vector>

using namespace std;

void FibonacciSeries(vector<int>& vFibSeries, short Number)
{
    vFibSeries.push_back(0);
    vFibSeries.push_back(1);

    // *(vFibSeries.end() - 1) ? value of last element
    // *(vFibSeries.end() - 2) ? value of second last element
    for (int i = 2; i <= Number; i++)
    {
        vFibSeries.push_back(*(vFibSeries.end() - 2) + *(vFibSeries.end() - 1));
    }
}

void PrintFibonacciSeries(const vector<int>& vFibSeries)
{
    for (const int& Num : vFibSeries)
    {
        cout << Num << '\t';
    }
    cout << endl;
}
int main()
{
    vector <int> vFibSeries;

    FibonacciSeries(vFibSeries, 10);
    PrintFibonacciSeries(vFibSeries);

    system("pause>0");
}
