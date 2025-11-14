#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile("F.txt");
    ofstream outputFile("G.txt");

    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "File could not be created" << endl;
        return 1;
    }

    int num;
    bool hasPositiveNumbers = false;

    while (inputFile >> num) {
        if (num > 0) {
            hasPositiveNumbers = true;

            double root = sqrt(num);

            outputFile << num << "," << fixed << setprecision(5) << root << endl;
        }
    }

    if (!hasPositiveNumbers) {
        cout << "No positive numbers found in the file" << endl;
    } else {
        cout << "Successfully processed positive numbers" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
