#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkTD(string line) {
    size_t pos = 0;
    int openCount = 0;

    while (true) {
        size_t openPos = line.find("<td>", pos);
        size_t closePos = line.find("</td>", pos);

        if (openPos == string::
        }
    }

    return openCount == 0;
}

void checkFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        if (checkTD(line)) {
            cout << "Line " << lineNumber << ": correct" << endl;
        } else {
            cout << "Line " << lineNumber << ": incorrect" << endl;
        }
        lineNumber++;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    checkFile(filename);

    return 0;
}
