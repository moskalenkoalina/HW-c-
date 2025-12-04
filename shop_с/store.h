/*
File: store.h
A header file with class and method declarations.
Done by Moskalenko Alina
Group: 2nd year, computer mathematics
Date 30.11.2025
*/

#ifndef STORE_H
#define STORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_CONTACT_LENGTH 100

// Базова структура Person
typedef struct {
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
} Person;

// Структура Buyer
typedef struct {
    Person person;
    double discount;
    int purchasesCount;
    bool isRegular;
    double totalSpent;
} Buyer;

// Структура Seller
typedef struct {
    Person person;
    double salary;
    double totalProfit;
    int itemsSold;
} Seller;

// Структура Manager
typedef struct {
    Person person;
} Manager;

// Структура Product
typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double cost;
    int quantity;
    int soldQuantity;
} Product;

// Структура Store
typedef struct {
    Manager manager;
    double balance;
    bool autoSave;

    Product* products;
    int productsCount;
    int productsCapacity;

    Seller* sellers;
    int sellersCount;
    int sellersCapacity;

    Buyer* buyers;
    int buyersCount;
    int buyersCapacity;
} Store;

// Функції для Person
void person_init(Person* person, const char* name, const char* contact);
void person_display(const Person* person);
void person_serialize(const Person* person, FILE* file);
void person_deserialize(Person* person, FILE* file);

// Функції для Buyer
void buyer_init(Buyer* buyer, const char* name, const char* contact, double discount, bool regular);
void buyer_display(const Buyer* buyer);
void buyer_serialize(const Buyer* buyer, FILE* file);
void buyer_deserialize(Buyer* buyer, FILE* file);

// Функції для Seller
void seller_init(Seller* seller, const char* name, const char* contact);
void seller_display(const Seller* seller);
void seller_serialize(const Seller* seller, FILE* file);
void seller_deserialize(Seller* seller, FILE* file);

// Функції для Manager
void manager_init(Manager* manager, const char* name, const char* contact);
void manager_display(const Manager* manager);

// Функції для Product
void product_init(Product* product, const char* name, double price, double cost, int quantity);
void product_display(const Product* product);
void product_serialize(const Product* product, FILE* file);
void product_deserialize(Product* product, FILE* file);

// Функції для Store
void store_init(Store* store, const Manager* manager, double initialBalance);
void store_destroy(Store* store);
void store_save_to_binary_file(Store* store);
void store_load_from_binary_file(Store* store);
void store_add_product(Store* store, const Product* product);
void store_add_seller(Store* store, const Seller* seller);
void store_add_buyer(Store* store, const Buyer* buyer);
bool store_purchase_items(Store* store, const char* buyerName, const char* sellerName,
                         const char* productName, int quantity);
void store_restock_product(Store* store, const char* productName, int quantity);
void store_calculate_salaries(Store* store, double profitShare);
void store_simulate_random_purchases(Store* store, int numberOfTransactions);
void store_simulate_random_restocking(Store* store);
void store_display_status(const Store* store);
void store_display_products(const Store* store);
void store_display_sellers(const Store* store);
void store_display_buyers(const Store* store);
void store_display_financial_report(const Store* store);
void store_manual_purchase_input(Store* store);
void store_clear_data(Store* store);

// Допоміжні функції
void clear_input();
int get_int_input(const char* prompt);
double get_double_input(const char* prompt);
void get_string_input(const char* prompt, char* buffer, int bufferSize);
char get_char_input(const char* prompt);
void initialize_store_with_sample_data(Store* store);
void manual_data_input(Store* store);
void manual_purchases_input(Store* store);
void simulate_day(Store* store, int day, bool automaticMode);
bool check_if_data_exists(void);



#endif