#include <iostream>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

void findMaxMin(ifstream &inputFile, int &max, int &min) {
    string line;
    min = INT_MAX;
    max = 0;

    while (getline(inputFile, line)) {
        int len = line.length();

        if (len > max) {
            max = len;
        }

        if (len < min) {
            min = len;
        }
    }
}

void writelines(ifstream &input, ofstream &output, int length) {
    string line;
    while (getline(input, line)) {
        if (line.length() == length) {
            output << line << endl;
        }
    }
}

int main() {
    string inputFile, outputFile;

    cout << "Enter name of input file: ";
    cin >> inputFile;
    cout << "Enter name of output file: ";
    cin >> outputFile;

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open()) {
        cout << "Error opening input file" << endl;
        return 1;
    }

    if (!fout.is_open()) {
        cout << "Error opening output file" << endl;
        return 1;
    }

    int max, min;
    findMaxMin(fin, max, min);

    fin.close();
    fin.open(inputFile);
    fout << "Minimum length is: " << min << endl;
    fout << "Strings with minimum length: " << endl;
    writelines(fin, fout, min);

    fin.close();
    fin.open(inputFile);
    fout << endl << "Maximum length is: " << max << endl;
    fout << "Strings with maximum length: " << endl;
    writelines(fin, fout, max);

    fin.close();
    fout.close();

    cout << "Result in file " << outputFile << endl;
    return 0;
}