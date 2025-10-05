#include <iostream>
using namespace std;

int main() {
    int a = -99;
    int b = -99;
    int c = -99;
    int n = 3;

    while (c <= 0) {
        int next = c + a + 100;
        a = b;
        b = c;
        c = next;
        n++;
    }

    cout << "min :" << c << endl;
    cout << "number:" << n << endl;

    return 0;
}