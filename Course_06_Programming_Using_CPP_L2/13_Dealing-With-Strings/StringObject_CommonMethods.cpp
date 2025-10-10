#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Original string
    string S1 = "My Name is Mohammad Abu-Hadhoud, I love programming.";

    //----------------------
    // Basic Info
    //----------------------
    cout << "Length: " << S1.length() << endl;        // Prints the length of the string
    cout << "Character at 3: " << S1.at(3) << endl;  // Returns the letter at position 3

    //----------------------
    // Modifying Strings
    //----------------------
    S1.append(" @ProgrammingAdvices");  // Adds to the end
    cout << "After append: " << S1 << endl;

    S1.insert(10, " Ali");               // Insert at position 10
    cout << "After insert: " << S1 << endl;

    S1.push_back('X');                    // Add a character at the end
    cout << "After push_back: " << S1 << endl;

    S1.pop_back();                        // Remove last character
    cout << "After pop_back: " << S1 << endl;

    //----------------------
    // Substrings and Searching
    //----------------------
    cout << "Substring (16,8): " << S1.substr(16, 8) << endl;  // Next 8 letters from pos 16

    cout << "Find 'Ali': " << S1.find("Ali") << endl;          // Finds Ali
    cout << "Find 'ali': " << S1.find("ali") << endl;          // Finds ali (not found)

    if(S1.find("ali") == string::npos)
        cout << "'ali' isn't found" << endl;

    //----------------------
    // Clearing and Checking
    //----------------------
    S1.clear();                       // Clears all letters
    cout << "After clear, S1: '" << S1 << "'" << endl;

    //----------------------
    // Replace Example
    //----------------------
    string s = "I like cats";
    s.replace(7, 4, "dogs");          // Replace 4 chars starting at index 7 with "dogs"
    cout << "After replace: " << s << endl;  // Output: I like dogs

    //----------------------
    // Erase Example
    //----------------------
    string t = "Hello World";
    t.erase(5, 6);                     // Erase 6 characters starting from index 5
    cout << "After erase: " << t << endl;  // Output: Hello

    //----------------------
    // Additional Common Methods
    //----------------------
    string u = "Example";

    cout << "Is empty? " << (u.empty() ? "Yes" : "No") << endl;  // Check if empty

    u.resize(4);                        // Resize string
    cout << "After resize: " << u << endl;  // Output: Exam

    string a = "Apple", b = "Banana";
    a.swap(b);                           // Swap contents
    cout << "After swap, a: " << a << ", b: " << b << endl;

    string c = "abc", d = "abd";
    cout << "Compare c vs d: " << c.compare(d) << endl;  // Negative because c < d

    // ✅ String functions that modify in place (no need to reassign)
    string t = "mohammad";
    t.erase(pos, len);
    t.append("text");
    t.insert(pos, "text");
    t.replace(pos, len, "text");
    t.clear();
    t.resize(newSize);
    t.pop_back();
    t.push_back('x');

    return 0;
}

