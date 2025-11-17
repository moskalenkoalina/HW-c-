#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string replaceWordsWithDigits(const string& line) {
    map<string, string> wordToDigit = {
        {"one", "1"}, {"two", "2"}, {"three", "3"},
        {"four", "4"}, {"five", "5"}, {"six", "6"},
        {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    stringstream ss(line);
    string word;
    vector<string> result;

    while (ss >> word) {
        if (wordToDigit.count(word)) {
            result.push_back(wordToDigit[word]);
        } else {
            result.push_back(word);
        }
    }

    string output;
    for (int i = 0; i < result.size(); i++) {
        output += result[i];
        if (i != result.size() - 1) output += " ";
    }

    return output;
}

int main() {
    ifstream fin("HW21");
    if (!fin) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        cout << "Original line: " << line << endl;
        string replaced = replaceWordsWithDigits(line);
        cout << "Replaced line: " << replaced << endl << endl;
    }

    fin.close();
    return 0;
}
