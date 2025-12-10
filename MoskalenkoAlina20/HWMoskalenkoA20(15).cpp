#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    vector<string> words;
    int n;
    string word;
    
    cout << "Enter number of words: ";
    cin >> n;
    
    cout << "Enter " << n << " English words:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
    }
    
    map<char, int> letterCount;
    map<char, int> totalLength;
    
    for (const auto& w : words) {
        if (!w.empty()) {
            char firstLetter = tolower(w[0]);
            letterCount[firstLetter]++;
            totalLength[firstLetter] += w.length();
        }
    }
    
    cout << "\nResults:" << endl;
    
    for (const auto& pair : letterCount) {
        char letter = pair.first;
        int count = pair.second;
        int length = totalLength[letter];
        
        cout << letter << " -> " << length << " (" << count << ")" << endl;
    }
    
    return 0;
}
