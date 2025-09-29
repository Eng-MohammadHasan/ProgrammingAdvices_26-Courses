## 1. Global variable (normal)
### ✅ Accessible across files.
```cpp
// file1.cpp
#include <iostream>
int g = 10;   // global variable

void Print() {
    std::cout << g << std::endl;
}
```
```cpp
// file2.cpp
extern int g;   // can access g from file1.cpp

int main() {
    g = 20;
    Print();   // prints 20
}

```

## 2. Global static variable
### ✅ Hidden to file1.cpp only, not accessible in file2.cpp.
```cpp
// file1.cpp
#include <iostream>
static int g = 10;   // static global variable

void Print() {
    std::cout << g << std::endl;
}
```
```cpp
// file2.cpp
extern int g;   // ❌ error: g is hidden (not visible here)

int main() {
    // cannot access g from file1.cpp
}
```

