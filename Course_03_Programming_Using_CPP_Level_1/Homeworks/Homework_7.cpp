#include <iostream>
using namespace std;

// This Homework is a Coding Solution for the previous Homework in {Course 1} ... (CH 15) :) 

int main()
{
    // First Column --->
    cout << (12 >= 12) << endl;
    cout << (12 > 7) << endl;
    cout << (8 < 6) << endl;
    cout << (8 == 8) << endl;
    cout << (12 <= 12) << endl;
    cout << (7 == 5) << endl;
    cout << "----------------------------\n";

    // Second Column --->
    cout << !(12 >= 12) << endl;
    cout << !(12 < 7) << endl;
    cout << !(8 < 6) << endl;
    cout << !(8 == 8) << endl;
    cout << !(12 <= 12) << endl;
    cout << ! (7 == 5) << endl;
    cout << "----------------------------\n";

    // Third Column --->
    cout << (1 && 1) << endl;
    cout << (true && 0) << endl;
    cout << (0 || 1) << endl;
    cout << (0 || 0) << endl;
    cout << !0 << endl; // Not False ! 
    cout << !(1 || 0) << endl;
    cout << "----------------------------\n";

    // Fourth Column --->
    cout << (7 == 7 && 7 > 5) << endl;
    cout << (7 == 7 && 7 < 5) << endl;
    cout << (7 == 7 || 7 < 5) << endl;
    cout << (7 < 7 || 7 > 5) << endl;
    cout << (!(7 == 7) && (7 < 5)) << endl;
    cout << ((7 == 7) && !(7 < 5)) << endl;
   
    return 0;
}
