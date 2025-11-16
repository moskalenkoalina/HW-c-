#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ifstream fin("tem1");
    if (!fin) {
        cout << "Could not open file!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        map<string, int> wordCount;
        vector<string> words;

        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
            wordCount[word]++;
        }

        cout << "Original: " << line << endl;
        cout << "Unique words: ";
        for (int i = 0; i < words.size(); i++) {
            if (wordCount[words[i]] == 1) {
                cout << words[i] << " ";
            }
        }
        cout << endl << endl;
    }

    fin.close();
    return 0;
}
