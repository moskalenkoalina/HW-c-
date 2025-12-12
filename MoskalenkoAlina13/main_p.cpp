
#include "product.h"
#include <iostream>

using namespace std;

Currency::Currency() {
    name = "UAH";
    value = 0;
    cents = 0;
}

Currency::Currency(string n, int v, int c) {
    name = n;
    value = v;
    cents = c;
}

void Currency::input() {
    cout << "Currency name: ";
    cin >> name;
    cout << "Whole part: ";
    cin >> value;
    cout << "Cents: ";
    cin >> cents;
}

void Currency::output() {
    cout << name << " " << value << ",";
    if (cents < 10) cout << "0";
    cout << cents;
}

Currency Currency::add(Currency other) {
    int v = value + other.value;
    int c = cents + other.cents;
    if (c >= 100) {
        v += 1;
        c -= 100;
    }
    return Currency(name, v, c);
}

Currency Currency::sub(Currency other) {
    int v = value - other.value;
    int c = cents - other.cents;
    if (c < 0) {
        v -= 1;
        c += 100;
    }
    return Currency(name, v, c);
}

Product::Product() {
    name = "";
    price = Currency("UAH", 0, 0);
    unit = "pcs";
}

Product::Product(string n, Currency p, string u) {
    name = n;
    price = p;
    unit = u;
}

void Product::input() {
    cout << "Product name: ";
    cin >> name;
    cout << "Price:\n";
    price.input();
    cout << "Unit: ";
    cin >> unit;
}

void Product::output() {
    cout << name << " - ";
    price.output();
    cout << " per " << unit;
}

Product Product::add(Product other) {
    Currency newPrice = price.add(other.price);
    return Product(name, newPrice, unit);
}

Product Product::sub(Product other) {
    Currency newPrice = price.sub(other.price);
    return Product(name, newPrice, unit);
}

Currency exchange(Currency c, double rate) {
    double total = c.getValue() + c.getCents() / 100.0;
    total *= rate;

    int v = (int)total;
    int c2 = (int)((total - v) * 100);

    return Currency("USD", v, c2);
}

Product exchange(Product p, double rate) {
    Currency newPrice = exchange(p.getPrice(), rate);
    return Product(p.getName(), newPrice, p.getUnit());
}

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

    cout << "\n\nExchange currency 1 with rate 0.85: ";
    Currency c5 = exchange(c1, 0.85);
    c5.output();

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

    cout << "\n\nSum of products: ";
    Product p3 = p1.add(p2);
    p3.output();

    cout << "\nDifference of products: ";
    Product p4 = p1.sub(p2);
    p4.output();

    cout << "\n\nExchange product 1 currency with rate 0.85: ";
    Product p5 = exchange(p1, 0.85);
    p5.output();

    return 0;
}
