#include <iostream>
#include <vector>
using namespace std;

/*
  ptr holds the address of the vector object itself, not its elements. 
  
  The vector object contains metadata (size, capacity, pointer to the actual array).
  
  The first element of the vector is somewhere else, inside the dynamically allocated array.
  
  To access elements through ptr:
    - Use (*ptr)[index]   → dereference then use []
    - Or use ptr->at(index) → arrow operator on the vector pointer
*/

struct stPizza {
    string name;
    double price;
};

int main() {
   
  // Example 1: vector of int
  vector<int> v = {10, 20, 30};
  vector<int>* ptr = &v;   // pointer to vector

  cout << (*ptr)[1] << endl;   // access with []
  cout << ptr->at(2) << endl;  // access with ->


  // Example 2: vector of structures
  vector<stPizza> vMenu = { {"Margherita", 5.5}, {"Pepperoni", 7.0} };
  vector<stPizza>* ptrMenu = &vMenu;   // pointer to vector of stPizza

  cout << (*ptrMenu)[0].name << " - $" << (*ptrMenu)[0].price << endl;  // access with []
  cout << ptrMenu->at(1).name << " - $" << ptrMenu->at(1).price << endl; // access with ->

  return 0;
}
