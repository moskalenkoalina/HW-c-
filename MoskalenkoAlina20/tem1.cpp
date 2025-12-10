#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

string cleanWord(const string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c) || c == '\'') {
            result += c;
        }
    }
    return result;
}

int main() {
    string filename = "english_text.txt";
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        cout << "Make sure 'english_text.txt' is in the same folder as the program." << endl;
        return 1;
    }
    
    map<string, int> wordFrequency;
    string line;
    
    cout << "Analyzing file: " << filename << endl;
    
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordFrequency[cleanedWord]++;
            }
        }
    }
    
    inputFile.close();
    
    cout << "\nAnalysis results:" << endl;
    cout << "Total unique words: " << wordFrequency.size() << endl;
    
    int totalWords = 0;
    for (const auto& pair : wordFrequency) totalWords += pair.second;
    cout << "Total words (with repetitions): " << totalWords << endl;
    
    cout << "\nAll words and their frequency:" << endl;
    cout << left << setw(20) << "Word" << setw(10) << "Count" << "Percentage" << endl;

    
    for (const auto& pair : wordFrequency) {
        double percentage = (pair.second * 100.0) / totalWords;
        cout << left << setw(20) << pair.first 
             << setw(10) << pair.second 
             << fixed << setprecision(2) << percentage << "%" << endl;
    }
    
    cout << "\nTop-10 most frequent words:" << endl;
    
    vector<pair<string, int>> wordsVector(wordFrequency.begin(), wordFrequency.end());
    sort(wordsVector.begin(), wordsVector.end(), 
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });
    
    int count = 0;
    for (const auto& pair : wordsVector) {
        if (count >= 10) break;
        cout << left << setw(20) << pair.first << setw(10) << pair.second;
        double percentage = (pair.second * 100.0) / totalWords;
        cout << fixed << setprecision(2) << percentage << "%" << endl;
        count++;
    }
    
    cout << "\nWords that occur only once:" << endl;
    
    int singleOccurrenceCount = 0;
    for (const auto& pair : wordFrequency) {
        if (pair.second == 1) singleOccurrenceCount++;
    }
    
    cout << "Number of words that occur once: " << singleOccurrenceCount << endl;
    cout << "This is " << fixed << setprecision(1) 
         << (singleOccurrenceCount * 100.0 / wordFrequency.size()) 
         << "% of all unique words." << endl;
    
    cout << "\nExamples (up to 20):" << endl;
    count = 0;
    for (const auto& pair : wordFrequency) {
        if (pair.second == 1) {
            cout << pair.first << " ";
            count++;
            if (count >= 20) break;
        }
    }
    cout << endl;
    
    return 0;
}
