/*
File: main.c
Testing all functions
Done by Moskalenko Alina
Group: 2nd year, computer mathematics
Date 30.11.2025
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Глобальні змінні для тестування
int passed = 0;
int failed = 0;

//  СТРУКТУРИ

typedef struct {
    char name[100];
    char contact[100];
} Person;

typedef struct {
    Person person;
    double discount;
    int purchasesCount;
    bool isRegular;
    double totalSpent;
} Buyer;

typedef struct {
    Person person;
    double salary;
    double totalProfit;
    int itemsSold;
} Seller;

typedef struct {
    char name[100];
    double price;
    double cost;
    int quantity;
    int soldQuantity;
} Product;

// ФУНКЦІЇ ТЕСТУВАННЯ

void test_person() {
    printf("\n=== Test Person ===\n");
    Person p;
    strcpy(p.name, "Ivan Petrenko");
    strcpy(p.contact, "ivan@email.com");

    if(strcmp(p.name, "Ivan Petrenko") == 0) {
        printf(" Name is correct\n");
        passed++;
    } else {
        printf(" Name is incorrect\n");
        failed++;
    }

    if(strcmp(p.contact, "ivan@email.com") == 0) {
        printf("Contact is correct\n");
        passed++;
    } else {
        printf(" Contact is incorrect\n");
        failed++;
    }
}

void test_buyer() {
    printf("\n=== Test Buyer ===\n");
    Buyer b;
    strcpy(b.person.name, "Maria Buyer");
    strcpy(b.person.contact, "maria@email.com");
    b.discount = 0.15;
    b.purchasesCount = 0;
    b.isRegular = false;
    b.totalSpent = 0.0;

    if(strcmp(b.person.name, "Maria Buyer") == 0) {
        printf("Buyer's name is correct\n");
        passed++;
    } else {
        printf("Buyer's name is incorrect\n");
        failed++;
    }

    if(b.discount == 0.15) {
        printf(" Discount 15%%\n");
        passed++;
    } else {
        printf("Discount is not 15%%\n");
        failed++;
    }

    if(b.purchasesCount == 0) {
        printf("✓Purchases count is 0\n");
        passed++;
    } else {
        printf("✗ Purchases count is not 0\n");
        failed++;
    }
}

void test_seller() {
    printf("\n=== Test Seller ===\n");
    Seller s;
    strcpy(s.person.name, "Peter Seller");
    strcpy(s.person.contact, "peter@store.com");
    s.salary = 0.0;
    s.totalProfit = 0.0;
    s.itemsSold = 0;

    if(strcmp(s.person.name, "Peter Seller") == 0) {
        printf(" Seller's name is correct\n");
        passed++;
    } else {
        printf("Seller's name is incorrect\n");
        failed++;
    }

    if(s.salary == 0.0) {
        printf("Salary 0 at the start\n");
        passed++;
    } else {
        printf("Salary is not 0\n");
        failed++;
    }
}

void test_product() {
    printf("\n=== Test Product ===\n");
    Product pr;
    strcpy(pr.name, "Phone");
    pr.price = 15000.0;
    pr.cost = 12000.0;
    pr.quantity = 25;
    pr.soldQuantity = 0;

    if(strcmp(pr.name, "Phone") == 0) {
        printf(" Product name is correct\n");
        passed++;
    } else {
        printf(" Product name is incorrect\n");
        failed++;
    }

    if(pr.price == 15000.0) {
        printf(" Price is 15000\n");
        passed++;
    } else {
        printf("Price is not 15000\n");
        failed++;
    }

    if(pr.quantity == 25) {
        printf(" Quantity is 25\n");
        passed++;
    } else {
        printf("✗ Quantity is not 25\n");
        failed++;
    }
}

void test_product_operations() {
    printf("\n=== Test Product Operations ===\n");
    Product pr;
    strcpy(pr.name, "Laptop");
    pr.quantity = 10;
    pr.soldQuantity = 0;

    // Симулюємо покупку
    int buyQuantity = 2;
    if(buyQuantity <= pr.quantity) {
        pr.quantity -= buyQuantity;
        pr.soldQuantity += buyQuantity;
    }

    if(pr.quantity == 8) {
        printf(" Quantity decreased to 8\n");
        passed++;
    } else {
        printf(" Quantity is not 8\n");
        failed++;
    }

    if(pr.soldQuantity == 2) {
        printf(" Sold 2 units\n");
        passed++;
    } else {
        printf("Sold not 2 units\n");
        failed++;
    }

    // Додаємо ще товару
    pr.quantity += 5;
    if(pr.quantity == 13) {
        printf("Quantity increased to 13\n");
        passed++;
    } else {
        printf(" Quantity is not 13\n");
        failed++;
    }
}

void test_buyer_operations() {
    printf("\n=== Test Buyer Operations ===\n");
    Buyer b;
    strcpy(b.person.name, "Test Buyer");
    b.discount = 0.1;
    b.purchasesCount = 0;
    b.isRegular = false;
    b.totalSpent = 0.0;

    // Робимо покупку
    b.totalSpent += 500.0;
    b.purchasesCount += 1;

    if(b.totalSpent == 500.0) {
        printf(" Spent 500\n");
        passed++;
    } else {
        printf("Did not spend 500\n");
        failed++;
    }

    if(b.purchasesCount == 1) {
        printf("Purchases count 1\n");
        passed++;
    } else {
        printf("Purchases count not 1\n");
        failed++;
    }

    // Перевіряємо статус постійного клієнта
    b.purchasesCount = 3;
    if(b.purchasesCount >= 3) {
        b.isRegular = true;
    }

    if(b.isRegular == true) {
        printf("Became a regular customer\n");
        passed++;
    } else {
        printf(" Did not become a regular customer\n");
        failed++;
    }
}

void test_seller_operations() {
    printf("\n=== Test Seller Operations ===\n");
    Seller s;
    strcpy(s.person.name, "Test Seller");
    s.salary = 0.0;
    s.totalProfit = 0.0;
    s.itemsSold = 0;

    // Продаємо товар
    s.totalProfit += 1000.0;
    s.itemsSold += 5;

    if(s.totalProfit == 1000.0) {
        printf("Income 1000\n");
        passed++;
    } else {
        printf("Income not 1000\n");
        failed++;
    }

    if(s.itemsSold == 5) {
        printf("Sold 5 units\n");
        passed++;
    } else {
        printf("Sold not 5 units\n");
        failed++;
    }

    // Розраховуємо зарплату
    s.salary = s.totalProfit * 0.1; // 10% commission

    if(s.salary == 100.0) {
        printf("Salary 100\n");
        passed++;
    } else {
        printf("Salary not 100\n");
        failed++;
    }
}

void test_simulation() {
    printf("\n=== Test Simulation ===\n");

    Product pr;
    strcpy(pr.name, "Book");
    pr.price = 200.0;
    pr.cost = 150.0;
    pr.quantity = 20;
    pr.soldQuantity = 0;

    Buyer b;
    strcpy(b.person.name, "Client");
    b.discount = 0.05;
    b.purchasesCount = 1;
    b.isRegular = false;
    b.totalSpent = 0.0;

    Seller s;
    strcpy(s.person.name, "Seller");
    s.totalProfit = 0.0;
    s.itemsSold = 0;

    // Симулюємо покупку
    int buyQuantity = 3;
    double priceWithoutDiscount = pr.price * buyQuantity;
    double priceWithDiscount = priceWithoutDiscount * (1 - b.discount);

    // Оновлюємо товар
    pr.quantity -= buyQuantity;
    pr.soldQuantity += buyQuantity;

    // Оновлюємо покупця
    b.totalSpent += priceWithDiscount;
    b.purchasesCount += 1;

    // Оновлюємо продавця
    double profitPerItem = pr.price - pr.cost;
    s.totalProfit += profitPerItem * buyQuantity;
    s.itemsSold += buyQuantity;

    // Перевіряємо чи став постійним клієнтом
    if(b.purchasesCount >= 3) {
        b.isRegular = true;
    }

    // Перевірки
    if(pr.quantity == 17) {
        printf("17 items left\n");
        passed++;
    } else {
        printf("Not 17 items left\n");
        failed++;
    }

    if(b.purchasesCount == 2) {
        printf("Purchases count 2\n");
        passed++;
    } else {
        printf("Purchases count not 2\n");
        failed++;
    }

    if(s.totalProfit > 0) {
        printf("Seller's profit > 0\n");
        passed++;
    } else {
        printf("Seller's profit is 0\n");
        failed++;
    }
}

void test_errors() {
    printf("\n=== Test Errors ===\n");

    Product pr;
    strcpy(pr.name, "Test Product");
    pr.quantity = 3;

    // Перевіряємо недостатню кількість
    int requestedQuantity = 5;
    bool purchasePossible = (requestedQuantity <= pr.quantity);

    if(purchasePossible == false) {
        printf(" Correctly identified impossible purchase\n");
        passed++;
    } else {
        printf(" Incorrectly identified purchase as possible\n");
        failed++;
    }

    // Перевіряємо від'ємну ціну
    double negativePrice = -50.0;
    bool correctPrice = (negativePrice >= 0);

    if(correctPrice == false) {
        printf("Negative price correctly identified as invalid\n");
        passed++;
    } else {
        printf("Negative price incorrectly identified as valid\n");
        failed++;
    }
}

// ОСНОВНА ФУНКЦІЯ

int main() {
    printf("STARTING STORE TESTING\n");
    printf("================================\n");

    // Запускаємо всі тести
    test_person();
    test_buyer();
    test_seller();
    test_product();
    test_product_operations();
    test_buyer_operations();
    test_seller_operations();
    test_simulation();
    test_errors();

    printf("\n================================\n");
    printf("TEST RESULTS:\n");
    printf("Tests passed: %d\n", passed);
    printf("Tests failed: %d\n", failed);
    printf("Total tests: %d\n", passed + failed);

    if(failed == 0) {
        printf("ALL TESTS PASSED! The system works correctly.\n");
    } else {
        printf("SOME TESTS FAILED! Something needs to be fixed.\n");
    }

    return failed;
}
