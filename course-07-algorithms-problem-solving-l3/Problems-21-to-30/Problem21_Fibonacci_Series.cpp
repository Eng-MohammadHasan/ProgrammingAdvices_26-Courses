#include <iostream>

using namespace std;

void FibonacciSeries(int arr[10])
{
    int Previous2 = 0, Previous1 = 1;
    arr[0] = 0;
    arr[1] = 1;

    for (short i = 1; i <= 10; i++)
    {
        arr[Previous1 + 1] = arr[Previous2] + arr[Previous1];
        Previous2++;
        Previous1++;
    }
}

void PrintArray(int arr[10])
{
    for (int i = 1; i <= 10; i++)
    {
        cout << arr[i] << '\t';
    }

    cout << endl;
}

int main()
{
    int arr[10];

    FibonacciSeries(arr);
    PrintArray(arr);

    system("pause>0");
}
