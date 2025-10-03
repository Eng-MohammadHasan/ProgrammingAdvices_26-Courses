#include <iostream>
#include <vector>
using namespace std;
/*

  ptr holds the address of the vector object itself, not its elements. 
  
  The vector object contains metadata (size, capacity, pointer to the actual array).
  
  The first element of the vector is somewhere else, inside the dynamically allocated array.
  
*/
int main() {
   
  vector<int> v = {10, 20, 30};

    vector<int>* ptr = &v;   // pointer to vector

    cout << (*ptr)[1] << endl;       // access with []
    cout << ptr->at(2) << endl;      // access with ->

    return 0;
  
}
