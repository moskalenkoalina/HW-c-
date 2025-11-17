#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitWords(const string& line) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

vector<string> findShortestWords(const vector<string>& words) {
    vector<string> shortestWords;
    if (words.empty()) return shortestWords;

    size_t minLength = words[0].size();
    for (const auto& w : words) {
        if (w.size() < minLength) minLength = w.size();
    }

    for (const auto& w : words) {
        if (w.size() == minLength) shortestWords.push_back(w);
    }

    return shortestWords;
}

void printResults(const vector<string>& shortestWords) {
    if (shortestWords.empty()) return;

    cout << "Shortest word (first): " << shortestWords[0] << endl;
    cout << "Shortest word (last): " << shortestWords.back() << endl;

    cout << "All shortest words: ";
    for (const auto& w : shortestWords) {
        cout << w << " ";
    }
    cout << endl;
}

int main() {
    ifstream fin("tem6");
    if (!fin) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        cout << "Original sentence: " << line << endl;

        vector<string> words = splitWords(line);
        if (words.empty()) {
            cout << "No words in this line!" << endl << endl;
            continue;
        }

        vector<string> shortestWords = findShortestWords(words);
        printResults(shortestWords);

        cout << endl;
    }

    fin.close();
    return 0;
}
