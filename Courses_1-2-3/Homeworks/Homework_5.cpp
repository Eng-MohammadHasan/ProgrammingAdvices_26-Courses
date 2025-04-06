#include <iostream>
using namespace std;

int main()
{
    int A, B;

    cout << "Please enter the first Number A : \n ";
    cin >> A;

    cout << "Please enter the second Number B : \n";
    cin >> B;

    cout << A << " + " << B << " = " << (A + B) << endl;
    cout << A << " - " << B << " = " << (A - B) << endl;
    cout << A << " * " << B << " = " << (A * B) << endl;
    cout << A << " / " << B << " = " << (A / B) << endl;
    cout << A << " % " << B << " = " << (A % B) << endl;
    
    return 0;
}