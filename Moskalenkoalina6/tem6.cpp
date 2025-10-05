#include <iostream>
using namespace std;


double chain_a(double b, int n) {
    if (n <= 0) return 0;
    double res = b;
    for (int i = 1; i < n; i++) {
        res = b + 1.0 / res;
    }
    return res;
}

double chain_b_indication(int n) {
    if (n <= 0) return 0;
    double res = 4 * n + 2;
    for (int k = 1; k <= n; k++) {
        res = 4 * (n - k) + 2 + 1.0 / res;
    }
    return res;
}


double chain_c(int n) {
    if (n <= 0) return 0;
    double res = n + 2;
    for (int i = n-1; i >= 1; i--) {
        res = 2 + 1.0 / res;
    }
    res = 1 + 1.0 / res;
    return res;
}

int main() {

    double b = 2.0;
    cout << " b=" << b << ":\n";
    for (int n = 1; n <= 5; n++) {
        cout << "n=" << n << ": " << chain_a(b, n) << endl;
    }

    for (int n = 1; n <= 5; n++) {
        cout << "n=" << n << ": " << chain_b_indication(n) << endl;
    }

    for (int n = 1; n <= 5; n++) {
        cout << "n=" << n << ": " << chain_c(n) << endl;
    }

    return 0;
}
