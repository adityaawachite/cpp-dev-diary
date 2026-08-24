
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    float p, c, m, b;
    float total;
    float percentage;
    char grade;
};

int main() {
    Student students[5];
    int topperIndex = 0;
    float maxPercentage = 0.0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;
        
        cout << "Enter Physics marks: ";
        cin >> students[i].p;
        
        cout << "Enter Chemistry marks: ";
        cin >> students[i].c;
        
        cout << "Enter Math marks: ";
        cin >> students[i].m;
        
        cout << "Enter Biology marks: ";
        cin >> students[i].b;

        students[i].total = students[i].p + students[i].c + students[i].m + students[i].b;
        students[i].percentage = students[i].total / 4.0;

        if (students[i].percentage >= 90) {
            students[i].grade = 'A';
        } else if (students[i].percentage >= 80) {
            students[i].grade = 'B';
        } else if (students[i].percentage >= 70) {
            students[i].grade = 'C';
        } else if (students[i].percentage >= 40) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }

        if (students[i].percentage > maxPercentage) {
            maxPercentage = students[i].percentage;
            topperIndex = i;
        }
        
        cout << "\n";
    }

    cout << "-----------------------------------\n";
    cout << "RESULT SHEET\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < 5; i++) {
        cout << "Name: " << students[i].name << "\n";
        cout << "Total Marks: " << students[i].total << " / 400\n";
        cout << "Percentage: " << students[i].percentage << "%\n";
        cout << "Grade: " << students[i].grade << "\n\n";
    }

    cout << "-----------------------------------\n";
    cout << "TOPPER OF THE CLASS\n";
    cout << "-----------------------------------\n";
    cout << "Name: " << students[topperIndex].name << "\n";
    cout << "Percentage: " << students[topperIndex].percentage << "%\n";
    cout << "Grade: " << students[topperIndex].grade << "\n";

    return 0;
}
