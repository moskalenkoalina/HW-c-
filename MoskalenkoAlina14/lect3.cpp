#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readWords(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open input file!" << endl;
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

string reverseWord(string word) {
    string rev = "";
    for (int i = word.length() - 1; i >= 0; i--) {
        rev += word[i];
    }
    return rev;
}

void writeWords(string filename, vector<string> words) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open output file!" << endl;
        exit(1);
    }

    for (string w : words) {
        file << w << " ";
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
    vector<string> decodedWords;

    for (string w : words) {
        decodedWords.push_back(reverseWord(w));
    }

    writeWords(outputFile, decodedWords);

    cout << "Words reversed and written to " << outputFile << endl;
    return 0;
}
