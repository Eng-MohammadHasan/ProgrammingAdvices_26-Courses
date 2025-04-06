#include <iostream>
using namespace std;

int main() {
    // Relational Operators ...
    short A, B;

    cout << "Please Enter the first Number A : " << endl;
    cin >> A;

    cout << "Please Enter the seconds Number B : " << endl;
    cin >> B;

    cout << endl << A << " = " << B << " is " << (A == B) << endl;

    cout << A << " != " << B << " is " << (A != B) << endl;

    cout << A << " > " << B << " is " << (A > B) << endl;

    cout << A << " < " << B << " is " << (A < B) << endl;

    cout << A << " >= " << B << " is " << (A >= B) << endl;

    cout << A << " <= " << B << " is " << (A <= B) << endl;

    return 0;
}
