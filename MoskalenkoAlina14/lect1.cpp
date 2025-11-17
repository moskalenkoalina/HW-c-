#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string readLineFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    string line;
    getline(file, line);
    file.close();
    return line;
}

string formatLine(const string& line) {
    string formatted_line = "";
    for (char c : line) {
        if (c == '+' || c == '-' || c == '=') {
            formatted_line += " ";
            formatted_line += c;
            formatted_line += " ";
        } else {
            formatted_line += c;
        }
    }
    return formatted_line;
}

double calculateResult(const string& formatted_line) {
    stringstream ss(formatted_line);
    double result;
    ss >> result;

    char op;
    double num;

    while (ss >> op) {
        if (op == '=') break;
        ss >> num;

        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        }
    }

    return result;
}

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    string line = readLineFromFile(filename);
    string formatted_line = formatLine(line);
    double result = calculateResult(formatted_line);

    cout << "Result: " << result << endl;

    return 0;
}
