#include "product.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Currency ===\n";
    Currency c1, c2;
    cout << "Currency 1:\n";
    c1.input();
    cout << "Currency 2:\n";
    c2.input();

    cout << "\nCurrency 1: ";
    c1.output();
    cout << "\nCurrency 2: ";
    c2.output();

    cout << "\n\nSum: ";
    Currency c3 = c1.add(c2);
    c3.output();

    cout << "\nDifference: ";
    Currency c4 = c1.sub(c2);
    c4.output();

    cout << "\n\n=== Product ===\n";
    Product p1, p2;
    cout << "Product 1:\n";
    p1.input();
    cout << "Product 2:\n";
    p2.input();

    cout << "\nProduct 1: ";
    p1.output();
    cout << "\nProduct 2: ";
    p2.output();

    cout << "\n\nProducts sum: ";
    Product p3 = p1.add(p2);
    p3.output();

    cout << "\nProducts difference: ";
    Product p4 = p1.sub(p2);
    p4.output();

    return 0;
}
