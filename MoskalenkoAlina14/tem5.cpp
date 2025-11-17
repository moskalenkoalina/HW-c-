#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string surname;
    int course;
    string group;
    vector<int> marks;
    double average;
};

vector<Student> readStudents(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open input file!" << endl;
        exit(1);
    }
    
    vector<Student> students;
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.surname >> s.course >> s.group;
        int mark;
        s.marks.clear();
        while (ss >> mark) {
            s.marks.push_back(mark);
        }
        students.push_back(s);
    }
    
    file.close();
    return students;
}

void calculateAverages(vector<Student>& students) {
    for (auto& s : students) {
        int sum = 0;
        for (int m : s.marks) sum += m;
        s.average = s.marks.empty() ? 0 : (double)sum / s.marks.size();
    }
}

Student findTopStudent(const vector<Student>& students) {
    Student top = students[0];
    for (const auto& s : students) {
        if (s.average > top.average) {
            top = s;
        }
    }
    return top;
}

void printStudent(const Student& s) {
    cout << "Top student: " << s.surname 
         << ", Course: " << s.course 
         << ", Group: " << s.group 
         << ", Average: " << s.average << endl;
}

int main() {
    string inputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;
    
    vector<Student> students = readStudents(inputFile);
    calculateAverages(students);
    Student top = findTopStudent(students);
    printStudent(top);
    
    return 0;
}
