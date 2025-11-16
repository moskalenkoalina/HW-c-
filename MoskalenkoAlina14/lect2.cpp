#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readWords(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        exit(1);
    }
    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return words;
}

vector<string> filterWords(vector<string> words, string prefix) {
    vector<string> result;
    for (string w : words) {
        if (w.find(prefix) == 0) {
            result.push_back(w);
        }
    }
    return result;
}

void writeWords(string filename, vector<string> words) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open output file!" << endl;
        exit(1);
    }
    for (string w : words) {
        file << w << endl;
    }
    file.close();
}

int main() {
    string inputFile, outputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter output file name: ";
    cin >> outputFile;

    vector<string> words = readWords(inputFile);

    vector<string> result;
    vector<string> prefixes = {"die", "der", "das"};

