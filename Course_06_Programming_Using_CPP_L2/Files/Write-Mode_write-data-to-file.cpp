#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream MyFile;

    // Open file in write mode (creates file if not exists, overwrites if exists)
    MyFile.open("MyFile.txt", ios::out); // ios::out → opens file for writing, and clears old content if the file already exists.

    if (MyFile.is_open()) {
        MyFile << "Hi, this is the first line\n";
        MyFile << "Hi, this is the second line\n";
        MyFile << "Hi, this is the third line\n";
        MyFile.close(); // close file after writing
    }

    return 0;
}