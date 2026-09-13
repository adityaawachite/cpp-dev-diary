
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Student {
    string* name;
    string* course;
    string* college;
    int age;
};

int main() {
    string path = "c:/user/college_data/public/merit_file.csv";
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    unordered_map<string, string*> memoryPool; // store unique strings
    vector<Student> students;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, course, college, ageStr;

        getline(ss, name, ',');
        getline(ss, course, ',');
        getline(ss, college, ',');
        getline(ss, ageStr, ',');

        // allocate or reuse memory for duplicates
        auto getPtr = [&](string &val) -> string* {
            if (memoryPool.find(val) == memoryPool.end()) {
                memoryPool[val] = new string(val);
            }
            return memoryPool[val];
        };

        Student s;
        s.name = getPtr(name);
        s.course = getPtr(course);
        s.college = getPtr(college);
        s.age = stoi(ageStr);

        students.push_back(s);
    }

    file.close();

    // Display with indexing order
    for (size_t i = 0; i < students.size(); i++) {
        cout << i << ": "
             << *students[i].name << ", "
             << *students[i].course << ", "
             << *students[i].college << ", "
             << students[i].age << endl;
    }

    return 0;
}