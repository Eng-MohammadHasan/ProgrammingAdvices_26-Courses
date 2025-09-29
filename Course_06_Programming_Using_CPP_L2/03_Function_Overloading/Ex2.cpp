#include <iostream>
using namespace std;

// Overloaded for 2 doubles
double MySum(double a, double b) {
    return a + b;
}

// Overloaded for 2, 3, or 4 integers (using default arguments)
int MySum(int a, int b, int c = 0, int d = 0) {
    return a + b + c + d;
}

// Overloaded for an array of integers
int MySum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Overloaded for an array of doubles
double MySum(const double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int main() {
    cout << MySum(10, 20) << endl;              // 2 integers
    cout << MySum(10.1, 20.1) << endl;          // 2 doubles
    cout << MySum(10, 20, 30) << endl;          // 3 integers
    cout << MySum(10, 20, 30, 40) << endl;      // 4 integers

    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.5, 3.5};

    cout << MySum(intArr, 5) << endl;           // array of integers
    cout << MySum(doubleArr, 3) << endl;        // array of doubles

    return 0;
}
