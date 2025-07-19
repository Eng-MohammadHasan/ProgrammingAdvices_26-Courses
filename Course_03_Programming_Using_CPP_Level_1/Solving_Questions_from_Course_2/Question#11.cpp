#include <iostream>

using namespace std;

void inputMarks(float marks[3]) {
   
    cout << "Enter Mark1: ";
    cin >> marks[0];
  
    cout << "Enter Mark2: ";
    cin >> marks[1];
  
    cout << "Enter Mark3: ";
    cin >> marks[2];
}

float calculateAverage(const float marks[3]) {
    return (marks[0] + marks[1] + marks[2]) / 3.0;
}

void displayResult(float average) {
    cout << "Average: " << average << endl;
    if (average >= 50) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

int main() {
    float marks[3];
  
    inputMarks(marks);
    float average = calculateAverage(marks);
    displayResult(average);
    return 0;
}
