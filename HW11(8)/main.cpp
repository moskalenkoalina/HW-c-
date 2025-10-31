#include <iostream>
#include <fstream>
#include "file_processor.h"

using namespace std;

void createSampleFile(const char* filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 1; i <= 20; i++) {
            file << i * 3 << " ";
            if (i % 5 == 0) file << endl;
        }
        file.close();
        cout << "Sample file '" << filename << "' created with 20 numbers." << endl;
    }
}

int main() {
    string inputFile, outputFile;
    int n;
    
    cout << " File Processor Program" << endl;
    cout << "This program reads numbers from file F and creates file G" << endl;
    cout << "with maximum values from groups of n numbers." << endl << endl;

    cout << "Enter input filename (F): ";
    cin >> inputFile;
    
    cout << "Enter output filename (G): ";
    cin >> outputFile;
    
    cout << "Enter natural number n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: n must be a natural number (positive integer)." << endl;
        return 1;
    }

    ifstream testFile(inputFile);
    if (!testFile.is_open()) {
        cout << "Input file '" << inputFile << "' not found." << endl;
        cout << "Would you like to create a sample file? (y/n): ";
        char choice;
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            createSampleFile(inputFile.c_str());
        } else {
            cout << "Please create the input file manually and run the program again." << endl;
            return 1;
        }
    } else {
        testFile.close();
    }

    processFiles(inputFile.c_str(), outputFile.c_str(), n);

    cout << endl << "Content of output file " << outputFile << ":" << endl;

    ifstream displayFile(outputFile);
    if (displayFile.is_open()) {
        string line;
        while (getline(displayFile, line)) {
            cout << line << endl;
        }
        displayFile.close();
    } else {
        cout << "Could not open output file for display." << endl;
    }

    
    return 0;
}