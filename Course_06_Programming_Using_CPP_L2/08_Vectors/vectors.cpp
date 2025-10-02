#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vNumbers = { 10, 20, 30, 40, 50 };

    cout << "Numbers Vector = ";

    // Range-based loop with reference
    // int& Number is a reference to each element of the vector one by one, not just the first one.
    for (int& Number : vNumbers)
    {
        cout << Number << "  ";
    }

    // Explanation of how the reference works:
    // ✅ What happens exactly:
    // 1. The loop iterates over every element in vNumbers.
    // 2. Number becomes an alias for the current element in each iteration.
    // 3. Modifying Number directly modifies that element in the vector.
    // So it’s like:
    // for (size_t i = 0; i < vNumbers.size(); i++)
    //     int& Number = vNumbers[i];

    cout << endl;

    return 0;
}
