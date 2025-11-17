#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string processStringNew(const string& input) {
    size_t colon_pos = input.find(':');
    if (colon_pos == string::npos) return input;

    size_t comma_pos = input.find(',', colon_pos + 1);
    if (comma_pos == string::npos) return input.substr(colon_pos);

    return input.substr(colon_pos, comma_pos - colon_pos);
}

void processStringInPlace(string& input) {
    size_t colon_pos = input.find(':');
    if (colon_pos == string::npos) return;

    size_t comma_pos = input.find(',', colon_pos + 1);
    if (comma_pos == string::npos) {
        input = input.substr(colon_pos);
        return;
    }

    input = input.substr(colon_pos, comma_pos - colon_pos);
}

int main() {
    ifstream fin("tem1");
    if (!fin) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        cout << "Original: " << line << endl;

        cout << "processStringNew: " << processStringNew(line) << endl;

        string copy = line;
        processStringInPlace(copy);
        cout << "processStringInPlace: " << copy << endl;

        cout << endl;
    }

    fin.close();
    return 0;
}
