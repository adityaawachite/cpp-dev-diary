
#include <iostream>
#include <string>
using namespace std;
class StudentResult {
private:
    int rollNumber;
    string studentName;
    float mathMarks;
    float scienceMarks;
    float englishMarks;
    float totalMarks;
    float averageMarks;
public:
    StudentResult() {
        rollNumber = 0;
        studentName = "Unknown";
        mathMarks = 0.0;
        scienceMarks = 0.0;
        englishMarks = 0.0;
        totalMarks = 0.0;
        averageMarks = 0.0;
    }
    ~StudentResult() {
        cout << "\nMemory freed for student record: " << studentName << endl;
    }
    void getData() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        
        cout << "Enter Student Name: ";
        getline(cin, studentName);
        
        cout << "Enter Math Marks: ";
        cin >> mathMarks;
        
        cout << "Enter Science Marks: ";
        cin >> scienceMarks;
        
        cout << "Enter English Marks: ";
        cin >> englishMarks;
    }
    void calculateResult() {
        totalMarks = mathMarks + scienceMarks + englishMarks;
        averageMarks = totalMarks / 3.0;
    }
    void displayResult() {
        cout << "\n===============================" << endl;
        cout << "         STUDENT RESULT        " << endl;
        cout << "===============================" << endl;
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name        : " << studentName << endl;
        cout << "Math        : " << mathMarks << endl;
        cout << "Science     : " << scienceMarks << endl;
        cout << "English     : " << englishMarks << endl;
        cout << "-------------------------------" << endl;
        cout << "Total Marks : " << totalMarks << endl;
        cout << "Average     : " << averageMarks << "%" << endl;
        
        if (averageMarks >= 40.0) {
            cout << "Result      : PASS" << endl;
        } else {
            cout << "Result      : FAIL" << endl;
        }
        cout << "===============================\n" << endl;
    }
};
int main() {
    StudentResult student1;
    
    student1.getData();
    student1.calculateResult();
    student1.displayResult();
    return 0;
}
