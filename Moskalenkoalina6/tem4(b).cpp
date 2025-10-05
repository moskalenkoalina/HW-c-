#include <iostream>
#include <cmath>
using namespace std;

double calculateProductB(int n) {
    double product = 1.0;
    double powerOfTwo = 2.0;

    for (int i = 1; i <= n; ++i) {
        double sign = (i % 2 == 1) ? 1.0 : -1.0;
        double term = 1.0 + sign * (i * i) / powerOfTwo;
        product *= term;
        powerOfTwo *= 2.0;
    }
    return product;
}

int main() {
    int n;
    cout << "n= ";
    cin >> n;
    double result = calculateProductB(n);
    cout << "P_n = " << result << endl;
    return 0;
}