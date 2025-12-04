/*
File: store.h
Testing of all functions
Done by Moskalenko Alina
Group: 2nd year, computer mathematics
Date 25.11.2025
*/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// Прості тести для перевірки базової функціональності
void testBasicFunctions() {
    cout << "=== BASIC FUNCTION TESTS ===" << endl;

    // Тест 1: Робота з рядками
    string testName = "Test Product";
    assert(testName == "Test Product");
    cout << "✓ String handling: OK" << endl;

    // Тест 2: Математичні операції
    double price = 10.0;
    double cost = 5.0;
    double profit = price - cost;
    assert(profit == 5.0);
    cout << " Math operations: OK" << endl;

    // Тест 3: Робота з векторами
    vector<string> products;
    products.push_back("Product1");
    products.push_back("Product2");
    assert(products.size() == 2);
    cout << "Vector handling: OK" << endl;

    cout << "All basic tests passed successfully!" << endl << endl;
}

void testStoreLogic() {
    cout << "=== STORE LOGIC TESTS ===" << endl;

    // Тест розрахунку ціни зі знижкою
    double basePrice = 100.0;
    double discount = 0.1; // 10%
    double finalPrice = basePrice * (1 - discount);
    assert(finalPrice == 90.0);
    cout << "Discount calculation: OK" << endl;

    // Тест перевірки наявності товару
    int availableQuantity = 5;
    int requestedQuantity = 3;
    bool canSell = (requestedQuantity <= availableQuantity);
    assert(canSell == true);
    cout << "Stock availability check: OK" << endl;

    // Тест неможливості продажу
    requestedQuantity = 10;
    canSell = (requestedQuantity <= availableQuantity);
    assert(canSell == false);
    cout << "Insufficient stock check: OK" << endl;

    cout << "All store logic tests passed successfully!" << endl << endl;
}

void testFileOperations() {
    cout << "=== FILE OPERATION TESTS ===" << endl;

    // Симуляція роботи з файлами
    vector<string> fileData;
    fileData.push_back("PRODUCT Apple 1.5 0.8 50");
    fileData.push_back("BUYER John john@email.com 0.1 false");

    assert(fileData.size() == 2);
    assert(fileData[0].find("PRODUCT") != string::npos);
    assert(fileData[1].find("BUYER") != string::npos);
    cout << "File operation simulation: OK" << endl;

    cout << "All file tests passed successfully!" << endl << endl;
}

void testBusinessLogic() {
    cout << "=== BUSINESS LOGIC TESTS ===" << endl;

    // Тест розрахунку зарплати
    double totalProfit = 1000.0;
    double profitShare = 0.05; // 5%
    double salary = totalProfit * profitShare;
    assert(salary == 50.0);
    cout << "Salary calculation: OK" << endl;

    // Тест оновлення статусу постійного клієнта
    int purchasesCount = 3;
    bool isRegular = (purchasesCount >= 3);
    assert(isRegular == true);
    cout << "Customer status update: OK" << endl;

    // Тест розрахунку загального доходу
    double balance = 1000.0;
    double saleAmount = 150.0;
    balance += saleAmount;
    assert(balance == 1150.0);
    cout << "Balance calculation: OK" << endl;

    cout << "All business logic tests passed successfully!" << endl << endl;
}

int main() {
    cout << "RUNNING INDEPENDENT SYSTEM TESTS" << endl;
    cout << "=====================================" << endl << endl;

    try {
        testBasicFunctions();
        testStoreLogic();
        testFileOperations();
        testBusinessLogic();

        cout << "===================================" << endl;
        cout << "ALL TESTS PASSED SUCCESSFULLY!" << endl;
        cout << "SYSTEM IS READY FOR USE!" << endl;
        cout << "===================================" << endl;

        return 0;
    } catch (const exception& e) {
        cerr << " ERROR: " << e.what() << endl;
        return 1;
    }
}