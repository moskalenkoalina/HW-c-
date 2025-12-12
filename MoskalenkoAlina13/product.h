#ifndef CLASSES_H
#define CLASSES_H

#include <string>

class Currency {
private:
    std::string name;
    int value;
    int cents;

public:
    Currency();
    Currency(std::string n, int v, int c);

    void input();
    void output();

    Currency add(Currency other);
    Currency sub(Currency other);

    std::string getName();
    int getValue();
    int getCents();
};

class Product {
private:
    std::string name;
    Currency price;
    std::string unit;

public:
    Product();
    Product(std::string n, Currency p, std::string u);

    void input();
    void output();

    Product add(Product other);
    Product sub(Product other);

    Currency getPrice();
    std::string getName();
    std::string getUnit();
};

#endif