#include <iostream>
using namespace std;

double calculateProductA(int n) {
    double product = 1.0;
    double factorial = 1.0;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        double term = 1.0 + 1.0 / factorial;
        product *= term;
    }
    return product;
}

int main() {
    int n;
    cout << "n=: ";
    cin >> n;
    double result = calculateProductA(n);
    cout << "P_n = " << result << endl;
    return 0;
}