#include "../file_processor.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void processFiles(const char* inputFile, const char* outputFile, int n) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);
    
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << inputFile << endl;
        return;
    }
    
    if (!fout.is_open()) {
        cerr << "Error: Cannot open output file " << outputFile << endl;
        fin.close();
        return;
    }
    
    vector<int> numbers;
    int num;

    while (fin >> num) {
        numbers.push_back(num);
    }
    
    int totalNumbers = numbers.size();
    
    if (totalNumbers == 0) {
        cout << "Input file is empty." << endl;
        fin.close();
        fout.close();
        return;
    }
    
    cout << "Total numbers in file F: " << totalNumbers << endl;
    cout << "Group size n: " << n << endl;

    int completeGroups = totalNumbers / n;
    
    for (int i = 0; i < completeGroups; i++) {
        int maxVal = INT_MIN;
        int startIndex = i * n;

        for (int j = 0; j < n; j++) {
            if (numbers[startIndex + j] > maxVal) {
                maxVal = numbers[startIndex + j];
            }
        }
        
        fout << maxVal << endl;
        cout << "Group " << i + 1 << " max: " << maxVal << endl;
    }

    int remainingNumbers = totalNumbers % n;
    
    if (remainingNumbers > 0) {
        int maxVal = INT_MIN;
        int startIndex = completeGroups * n;
        
        for (int i = 0; i < remainingNumbers; i++) {
            if (numbers[startIndex + i] > maxVal) {
                maxVal = numbers[startIndex + i];
            }
        }
        
        fout << maxVal << endl;
        cout << "Last incomplete group max: " << maxVal << endl;
        cout << "Remaining numbers in last group: " << remainingNumbers << endl;
    }

    if (totalNumbers % n == 0) {
        cout << "Case 1: Number of components is divisible by n" << endl;
        cout << "Complete groups: " << completeGroups << endl;
    } else {
        cout << "Case 2: Number of components is NOT divisible by n" << endl;
        cout << "Complete groups: " << completeGroups << endl;
        cout << "Numbers in last incomplete group: " << remainingNumbers << endl;
    }
    
    fin.close();
    fout.close();
    cout << "Processing completed. Results written to " << outputFile << endl;
}