#include <iostream>
#include<fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream inputFile("F.txt");
    ofstream outputFile("G.txt");

    if (!inputFile) {
        cout << "File could not be opened" << endl;
        return 0;

    }

    if (!outputFile) {
        cout << "File could not be created" << endl;
        return 0;

    }

    int num;
    while (inputFile >> num) {
        if (num > 0) {
            double root = sqrt(num);
            outputFile << num<< ",";
            int int_num = int(root);
            outputFile << int_num << ".";

            double fractional = root - int_num;

            for (int i = 0; i < 5; i++) {
                fractional *= 10;
                int digit = (int)fractional;
                outputFile << digit;
                fractional -= digit;
            }
            outputFile << endl;



        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
};
