#include <iostream>
using namespace std;

// Function overloads
double MySum(double a, double b) {
    return a + b;
}

int MySum(int a, int b) {
    return a + b;
}

int MySum(int a, int b, int c) {
    return a + b + c;
}

int MySum(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main() {
    cout << MySum(10, 20) << endl;          // 2 integers
    cout << MySum(10.1, 20.1) << endl;      // 2 doubles
    cout << MySum(10, 20, 30) << endl;      // 3 integers
    cout << MySum(10, 20, 30, 40) << endl;  // 4 integers

    return 0;
}
