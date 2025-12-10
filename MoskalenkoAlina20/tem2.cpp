#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("english_text.txt");
    
    if (!file) {
        cout << "Error! Cannot open file english_text.txt" << endl;
        cout << "Make sure the file is in the same folder as the program." << endl;
        return 1;
    }
    
    map<string, int> wordCount;
    string word;
    int totalWords = 0;
    
    cout << "Reading file..." << endl;
    
    while (file >> word) {
        string cleanWord = "";
        for (char c : word) {
            if (isalpha(c)) {
                cleanWord += c;
            }
        }
        if (!cleanWord.empty()) {
            wordCount[cleanWord]++;
            totalWords++;
        }
    }
    
    file.close();

    cout << "          ANALYSIS RESULTS            " << endl;
    
    cout << "Total words found: " << totalWords << endl;
    cout << "Unique words: " << wordCount.size() << endl;
    
    cout << "\nWord list and count:\n" << endl;
    cout << left << setw(20) << "Word" << "Count" << endl;
    
    for (const auto& item : wordCount) {
        cout << left << setw(20) << item.first << item.second << endl;
    }
    
    string mostCommonWord;
    int maxCount = 0;
    for (const auto& item : wordCount) {
        if (item.second > maxCount) {
            maxCount = item.second;
            mostCommonWord = item.first;
        }
    }

    cout << "Most common word: '" << mostCommonWord 
         << "' (appears " << maxCount << " times)" << endl;
    
    int singleWords = 0;
    for (const auto& item : wordCount) {
        if (item.second == 1) {
            singleWords++;
        }
    }
    
    cout << "Words that appear only once: " << singleWords << endl;
    
    return 0;
}
