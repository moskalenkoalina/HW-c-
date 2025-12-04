/*
File: store.c
A file implementing the logic of the store and file operations.
Done by Moskalenko Alina
Group: 2nd year, computer mathematics
Date 30.11.2025
*/

#include "store.h"
#include <time.h>

// Реалізація функцій для Person
void person_init(Person* person, const char* name, const char* contact) {
    strncpy(person->name, name, MAX_NAME_LENGTH - 1);
    strncpy(person->contact, contact, MAX_CONTACT_LENGTH - 1);
    person->name[MAX_NAME_LENGTH - 1] = '\0';
    person->contact[MAX_CONTACT_LENGTH - 1] = '\0';
}

void person_display(const Person* person) {
    printf("Name: %s, Contact: %s", person->name, person->contact);
}

void person_serialize(const Person* person, FILE* file) {
    size_t nameLen = strlen(person->name) + 1;
    size_t contactLen = strlen(person->contact) + 1;

    fwrite(&nameLen, sizeof(size_t), 1, file);
    fwrite(person->name, sizeof(char), nameLen, file);

    fwrite(&contactLen, sizeof(size_t), 1, file);
    fwrite(person->contact, sizeof(char), contactLen, file);
}

void person_deserialize(Person* person, FILE* file) {
    size_t nameLen, contactLen;

    fread(&nameLen, sizeof(size_t), 1, file);
    fread(person->name, sizeof(char), nameLen, file);

    fread(&contactLen, sizeof(size_t), 1, file);
    fread(person->contact, sizeof(char), contactLen, file);
}

// Реалізація функцій для Buyer
void buyer_init(Buyer* buyer, const char* name, const char* contact, double discount, bool regular) {
    person_init(&buyer->person, name, contact);
    buyer->discount = discount;
    buyer->purchasesCount = 0;
    buyer->isRegular = regular;
    buyer->totalSpent = 0.0;
}

void buyer_display(const Buyer* buyer) {
    printf("Buyer - ");
    person_display(&buyer->person);
    printf(", Discount: %.1f%%, Purchases: %d, Regular: %s, Total Spent: %.2f USD\n",
           buyer->discount * 100, buyer->purchasesCount,
           buyer->isRegular ? "Yes" : "No", buyer->totalSpent);
}

void buyer_serialize(const Buyer* buyer, FILE* file) {
    person_serialize(&buyer->person, file);
    fwrite(&buyer->discount, sizeof(double), 1, file);
    fwrite(&buyer->purchasesCount, sizeof(int), 1, file);
    fwrite(&buyer->isRegular, sizeof(bool), 1, file);
    fwrite(&buyer->totalSpent, sizeof(double), 1, file);
}

void buyer_deserialize(Buyer* buyer, FILE* file) {
    person_deserialize(&buyer->person, file);
    fread(&buyer->discount, sizeof(double), 1, file);
    fread(&buyer->purchasesCount, sizeof(int), 1, file);
    fread(&buyer->isRegular, sizeof(bool), 1, file);
    fread(&buyer->totalSpent, sizeof(double), 1, file);
}

// Реалізація функцій для Seller
void seller_init(Seller* seller, const char* name, const char* contact) {
    person_init(&seller->person, name, contact);
    seller->salary = 0.0;
    seller->totalProfit = 0.0;
    seller->itemsSold = 0;
}

void seller_display(const Seller* seller) {
    printf("Seller - ");
    person_display(&seller->person);
    printf(", Salary: %.2f USD, Items Sold: %d, Total Profit: %.2f USD\n",
           seller->salary, seller->itemsSold, seller->totalProfit);
}

void seller_serialize(const Seller* seller, FILE* file) {
    person_serialize(&seller->person, file);
    fwrite(&seller->salary, sizeof(double), 1, file);
    fwrite(&seller->totalProfit, sizeof(double), 1, file);
    fwrite(&seller->itemsSold, sizeof(int), 1, file);
}

void seller_deserialize(Seller* seller, FILE* file) {
    person_deserialize(&seller->person, file);
    fread(&seller->salary, sizeof(double), 1, file);
    fread(&seller->totalProfit, sizeof(double), 1, file);
    fread(&seller->itemsSold, sizeof(int), 1, file);
}

// Реалізація функцій для Manager
void manager_init(Manager* manager, const char* name, const char* contact) {
    person_init(&manager->person, name, contact);
}

void manager_display(const Manager* manager) {
    printf("Manager - ");
    person_display(&manager->person);
    printf("\n");
}

// Реалізація функцій для Product
void product_init(Product* product, const char* name, double price, double cost, int quantity) {
    strncpy(product->name, name, MAX_NAME_LENGTH - 1);
    product->name[MAX_NAME_LENGTH - 1] = '\0';
    product->price = price;
    product->cost = cost;
    product->quantity = quantity;
    product->soldQuantity = 0;
}

void product_display(const Product* product) {
    double profitPerItem = product->price - product->cost;
    printf("Product: %s, Price: %.2f USD, Cost: %.2f USD, Quantity: %d, Sold: %d, Profit per item: %.2f USD\n",
           product->name, product->price, product->cost, product->quantity,
           product->soldQuantity, profitPerItem);
}

void product_serialize(const Product* product, FILE* file) {
    size_t nameLen = strlen(product->name) + 1;
    fwrite(&nameLen, sizeof(size_t), 1, file);
    fwrite(product->name, sizeof(char), nameLen, file);

    fwrite(&product->price, sizeof(double), 1, file);
    fwrite(&product->cost, sizeof(double), 1, file);
    fwrite(&product->quantity, sizeof(int), 1, file);
    fwrite(&product->soldQuantity, sizeof(int), 1, file);
}

void product_deserialize(Product* product, FILE* file) {
    size_t nameLen;
    fread(&nameLen, sizeof(size_t), 1, file);
    fread(product->name, sizeof(char), nameLen, file);

    fread(&product->price, sizeof(double), 1, file);
    fread(&product->cost, sizeof(double), 1, file);
    fread(&product->quantity, sizeof(int), 1, file);
    fread(&product->soldQuantity, sizeof(int), 1, file);
}

// Допоміжні функції для динамічних масивів
static void ensure_products_capacity(Store* store) {
    if (store->productsCount >= store->productsCapacity) {
        store->productsCapacity = store->productsCapacity == 0 ? 10 : store->productsCapacity * 2;
        store->products = realloc(store->products, store->productsCapacity * sizeof(Product));
    }
}

static void ensure_sellers_capacity(Store* store) {
    if (store->sellersCount >= store->sellersCapacity) {
        store->sellersCapacity = store->sellersCapacity == 0 ? 10 : store->sellersCapacity * 2;
        store->sellers = realloc(store->sellers, store->sellersCapacity * sizeof(Seller));
    }
}

static void ensure_buyers_capacity(Store* store) {
    if (store->buyersCount >= store->buyersCapacity) {
        store->buyersCapacity = store->buyersCapacity == 0 ? 10 : store->buyersCapacity * 2;
        store->buyers = realloc(store->buyers, store->buyersCapacity * sizeof(Buyer));
    }
}

// Реалізація функцій для Store
void store_init(Store* store, const Manager* manager, double initialBalance) {
    store->manager = *manager;
    store->balance = initialBalance;
    store->autoSave = false;

    store->products = NULL;
    store->productsCount = 0;
    store->productsCapacity = 0;

    store->sellers = NULL;
    store->sellersCount = 0;
    store->sellersCapacity = 0;

    store->buyers = NULL;
    store->buyersCount = 0;
    store->buyersCapacity = 0;

    store_load_from_binary_file(store);
}

void store_destroy(Store* store) {
    store_save_to_binary_file(store);
    free(store->products);
    free(store->sellers);
    free(store->buyers);
}

void store_save_to_binary_file(Store* store) {
    // Зберігаємо продукти
    FILE* productFile = fopen("products.bin", "wb");
    if (productFile) {
        for (int i = 0; i < store->productsCount; i++) {
            product_serialize(&store->products[i], productFile);
        }
        fclose(productFile);
    }

    // Зберігаємо продавців
    FILE* sellerFile = fopen("sellers.bin", "wb");
    if (sellerFile) {
        for (int i = 0; i < store->sellersCount; i++) {
            seller_serialize(&store->sellers[i], sellerFile);
        }
        fclose(sellerFile);
    }

    // Зберігаємо покупців
    FILE* buyerFile = fopen("buyers.bin", "wb");
    if (buyerFile) {
        for (int i = 0; i < store->buyersCount; i++) {
            buyer_serialize(&store->buyers[i], buyerFile);
        }
        fclose(buyerFile);
    }

    // Зберігаємо баланс
    FILE* balanceFile = fopen("balance.bin", "wb");
    if (balanceFile) {
        fwrite(&store->balance, sizeof(double), 1, balanceFile);
        fclose(balanceFile);
    }

    // Зберігаємо менеджера
    FILE* managerFile = fopen("manager.bin", "wb");
    if (managerFile) {
        person_serialize(&store->manager.person, managerFile);
        fclose(managerFile);
    }

    printf("Data saved to binary files successfully!\n");
}

void store_load_from_binary_file(Store* store) {
    // Завантажуємо продукти
    FILE* productFile = fopen("products.bin", "rb");
    if (productFile) {
        while (!feof(productFile)) {
            Product product;
            product_deserialize(&product, productFile);
            if (!feof(productFile)) {
                store_add_product(store, &product);
            }
        }
        fclose(productFile);
    }


    // Завантажуємо продавців
    FILE* sellerFile = fopen("sellers.bin", "rb");
    if (sellerFile) {
        while (!feof(sellerFile)) {
            Seller seller;
            seller_deserialize(&seller, sellerFile);
            if (!feof(sellerFile)) {
                store_add_seller(store, &seller);
            }
        }
        fclose(sellerFile);
    }

    // Завантажуємо покупців
    FILE* buyerFile = fopen("buyers.bin", "rb");
    if (buyerFile) {
        while (!feof(buyerFile)) {
            Buyer buyer;
            buyer_deserialize(&buyer, buyerFile);
            if (!feof(buyerFile)) {
                store_add_buyer(store, &buyer);
            }
        }
        fclose(buyerFile);
    }

    // Завантажуємо баланс
    FILE* balanceFile = fopen("balance.bin", "rb");
    if (balanceFile) {
        fread(&store->balance, sizeof(double), 1, balanceFile);
        fclose(balanceFile);
    }

    // Завантажуємо менеджера
    FILE* managerFile = fopen("manager.bin", "rb");
    if (managerFile) {
        person_deserialize(&store->manager.person, managerFile);
        fclose(managerFile);
    }

    printf("Data loaded from binary files successfully!\n");
}

void store_add_product(Store* store, const Product* product) {
    ensure_products_capacity(store);
    store->products[store->productsCount++] = *product;

    if (store->autoSave) {
        FILE* file = fopen("products.bin", "ab");
        if (file) {
            product_serialize(product, file);
            fclose(file);
        }
    }
}

void store_add_seller(Store* store, const Seller* seller) {
    ensure_sellers_capacity(store);
    store->sellers[store->sellersCount++] = *seller;

    if (store->autoSave) {
        FILE* file = fopen("sellers.bin", "ab");
        if (file) {
            seller_serialize(seller, file);
            fclose(file);
        }
    }
}

void store_add_buyer(Store* store, const Buyer* buyer) {
    ensure_buyers_capacity(store);
    store->buyers[store->buyersCount++] = *buyer;

    if (store->autoSave) {
        FILE* file = fopen("buyers.bin", "ab");
        if (file) {
            buyer_serialize(buyer, file);
            fclose(file);
        }
    }
}

Product* store_find_product(Store* store, const char* productName) {
    for (int i = 0; i < store->productsCount; i++) {
        if (strcmp(store->products[i].name, productName) == 0) {
            return &store->products[i];
        }
    }
    return NULL;
}

Seller* store_find_seller(Store* store, const char* sellerName) {
    for (int i = 0; i < store->sellersCount; i++) {
        if (strcmp(store->sellers[i].person.name, sellerName) == 0) {
            return &store->sellers[i];
        }
    }
    return NULL;
}

Buyer* store_find_buyer(Store* store, const char* buyerName) {
    for (int i = 0; i < store->buyersCount; i++) {
        if (strcmp(store->buyers[i].person.name, buyerName) == 0) {
            return &store->buyers[i];
        }
    }
    return NULL;
}

bool store_purchase_items(Store* store, const char* buyerName, const char* sellerName,
                         const char* productName, int quantity) {
    Product* product = store_find_product(store, productName);
    Seller* seller = store_find_seller(store, sellerName);
    Buyer* buyer = store_find_buyer(store, buyerName);

    if (!product || !seller || !buyer || quantity <= 0) {
        return false;
    }

    if (product->quantity < quantity) {
        return false;
    }

    double basePrice = product->price * quantity;
    double finalPrice = basePrice * (1 - buyer->discount);

    if (buyer->isRegular) {
        finalPrice *= 0.9;
    }

    double profitPerItem = product->price - product->cost;
    double totalProfitForSeller = profitPerItem * quantity;

    product->quantity -= quantity;
    product->soldQuantity += quantity;
    store->balance += finalPrice;
    seller->totalProfit += totalProfitForSeller;
    seller->itemsSold += quantity;
    buyer->purchasesCount++;
    buyer->totalSpent += finalPrice;

    if (buyer->purchasesCount >= 3 && !buyer->isRegular) {
        buyer->isRegular = true;
    }

    if (store->autoSave) {
        store_save_to_binary_file(store);
    }

    return true;
}

void store_restock_product(Store* store, const char* productName, int quantity) {
    Product* product = store_find_product(store, productName);
    if (product) {
        product->quantity += quantity;
        if (store->autoSave) {
            store_save_to_binary_file(store);
        }
    }
}

void store_calculate_salaries(Store* store, double profitShare) {
    for (int i = 0; i < store->sellersCount; i++) {
        store->sellers[i].salary = store->sellers[i].totalProfit * profitShare;
    }
    if (store->autoSave) {
        store_save_to_binary_file(store);
    }
}

void store_simulate_random_purchases(Store* store, int numberOfTransactions) {
    srand(time(NULL));

    if (store->productsCount == 0 || store->sellersCount == 0 || store->buyersCount == 0) {
        printf("Cannot simulate purchases: need products, sellers and buyers\n");
        return;
    }

    int successfulTransactions = 0;
    for (int i = 0; i < numberOfTransactions; i++) {
        int productIndex = rand() % store->productsCount;
        int sellerIndex = rand() % store->sellersCount;
        int buyerIndex = rand() % store->buyersCount;
        int quantity = 1 + rand() % 5;

        const char* productName = store->products[productIndex].name;
        const char* sellerName = store->sellers[sellerIndex].person.name;
        const char* buyerName = store->buyers[buyerIndex].person.name;

        if (store_purchase_items(store, buyerName, sellerName, productName, quantity)) {
            successfulTransactions++;
        }
    }

    printf("Random purchases simulation: %d/%d successful transactions\n",
           successfulTransactions, numberOfTransactions);
}

void store_simulate_random_restocking(Store* store) {
    srand(time(NULL));

    if (store->productsCount == 0) {
        printf("No products to restock\n");
        return;
    }

    int productIndex = rand() % store->productsCount;
    int quantity = 5 + rand() % 16;

    store_restock_product(store, store->products[productIndex].name, quantity);
}

void store_display_status(const Store* store) {
    printf("\n=== STORE STATUS ===\n");
    manager_display(&store->manager);
    printf("Balance: %.2f USD\n", store->balance);
    printf("Products in stock: %d\n", store->productsCount);
    printf("Sellers: %d\n", store->sellersCount);
    printf("Buyers: %d\n", store->buyersCount);
}

void store_display_products(const Store* store) {
    printf("\n=== PRODUCTS ===\n");
    if (store->productsCount == 0) {
        printf("No products available.\n");
    } else {
        for (int i = 0; i < store->productsCount; i++) {
            product_display(&store->products[i]);
        }
    }
}

void store_display_sellers(const Store* store) {
    printf("\n=== SELLERS ===\n");
    if (store->sellersCount == 0) {
        printf("No sellers available.\n");
    } else {
        for (int i = 0; i < store->sellersCount; i++) {
            seller_display(&store->sellers[i]);
        }
    }
}

void store_display_buyers(const Store* store) {
    printf("\n=== BUYERS ===\n");
    if (store->buyersCount == 0) {
        printf("No buyers available.\n");
    } else {
        for (int i = 0; i < store->buyersCount; i++) {
            buyer_display(&store->buyers[i]);
        }
    }
}

void store_display_financial_report(const Store* store) {
    printf("\n=== FINANCIAL REPORT ===\n");
    printf("Current Balance: %.2f USD\n", store->balance);

    double totalSales = 0;
    int totalItemsSold = 0;
    for (int i = 0; i < store->sellersCount; i++) {
        totalSales += store->sellers[i].totalProfit;
        totalItemsSold += store->sellers[i].itemsSold;
    }

    printf("Total Sales: %.2f USD\n", totalSales);
    printf("Total Items Sold: %d\n", totalItemsSold);

    double totalSalaries = 0;
    for (int i = 0; i < store->sellersCount; i++) {
        totalSalaries += store->sellers[i].salary;
    }
    printf("Total Salaries: %.2f USD\n", totalSalaries);

    double profit = totalSales - totalSalaries;
    printf("Net Profit: %.2f USD\n", profit);
}

void store_manual_purchase_input(Store* store) {
    if (store->productsCount == 0 || store->sellersCount == 0 || store->buyersCount == 0) {
        printf("Cannot make purchase: need products, sellers and buyers\n");
        return;
    }

    clear_input();

    // Показуємо доступних покупців
    printf("\nAvailable buyers:\n");
    for (int i = 0; i < store->buyersCount; i++) {
        printf("%d. %s (Discount: %.1f%%)\n", i + 1,
               store->buyers[i].person.name, store->buyers[i].discount * 100);
    }

    int buyerChoice = get_int_input("Select buyer (enter number): ");
    if (buyerChoice < 1 || buyerChoice > store->buyersCount) {
        printf("Invalid buyer selection!\n");
        return;
    }
    const char* buyerName = store->buyers[buyerChoice - 1].person.name;

    // Показуємо доступних продавців
    printf("\nAvailable sellers:\n");
    for (int i = 0; i < store->sellersCount; i++) {
        printf("%d. %s\n", i + 1, store->sellers[i].person.name);
    }

    int sellerChoice = get_int_input("Select seller (enter number): ");
    if (sellerChoice < 1 || sellerChoice > store->sellersCount) {
        printf("Invalid seller selection!\n");
        return;
    }
    const char* sellerName = store->sellers[sellerChoice - 1].person.name;

    bool continueShopping = true;
    while (continueShopping) {
        // Показуємо доступні товари
        printf("\nAvailable products:\n");
        for (int i = 0; i < store->productsCount; i++) {
            double profitPerItem = store->products[i].price - store->products[i].cost;
            printf("%d. %s (Price: %.2f, Available: %d, Profit per item: %.2f)\n",
                   i + 1, store->products[i].name, store->products[i].price,
                   store->products[i].quantity, profitPerItem);
        }

        int productChoice = get_int_input("Select product (enter number, or 0 to finish): ");
        if (productChoice == 0) {
            continueShopping = false;
            break;
        }

        if (productChoice < 1 || productChoice > store->productsCount) {
            printf("Invalid product selection!\n");
            continue;
        }

        const char* productName = store->products[productChoice - 1].name;
        Product* selectedProduct = store_find_product(store, productName);

        if (!selectedProduct) {
            printf("Product not found!\n");
            continue;
        }

        bool quantityValid = false;
        while (!quantityValid) {
            int quantity = get_int_input("Enter quantity: ");

            if (quantity <= 0) {
                printf("Quantity must be positive!\n");
                continue;
            }

            if (store_purchase_items(store, buyerName, sellerName, productName, quantity)) {
                printf("Purchase completed successfully! %d x %s\n", quantity, productName);
                quantityValid = true;

                char continueChoice = get_char_input("Do you want to continue shopping? (y/n): ");
                if (continueChoice == 'n' || continueChoice == 'N') {
                    continueShopping = false;
                }
            } else {
                printf("Purchase failed! Not enough quantity of %s\n", productName);
                printf("Available: %d\n", selectedProduct->quantity);

                char retryChoice = get_char_input("Do you want to try different quantity? (y/n): ");
                if (retryChoice == 'n' || retryChoice == 'N') {
                    quantityValid = true;
                }
            }
        }
    }

    printf("Shopping completed!\n");
}

void store_clear_data(Store* store) {
    store->productsCount = 0;
    store->sellersCount = 0;
    store->buyersCount = 0;
    store->balance = 15000.0;

    remove("products.bin");
    remove("sellers.bin");
    remove("buyers.bin");
    remove("balance.bin");
    remove("manager.bin");
}

// Допоміжні функції
void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_int_input(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_input();
            return value;
        } else {
            printf("Invalid input. Please enter a number.\n");
            clear_input();
        }
    }
}

double get_double_input(const char* prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1) {
            clear_input();
            return value;
        } else {
            printf("Invalid input. Please enter a number.\n");
            clear_input();
        }
    }
}

void get_string_input(const char* prompt, char* buffer, int bufferSize) {
    printf("%s", prompt);
    fgets(buffer, bufferSize, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
}

char get_char_input(const char* prompt) {
    char buffer[10];
    get_string_input(prompt, buffer, sizeof(buffer));
    return buffer[0];
}

void initialize_store_with_sample_data(Store* store) {
    printf("\n=== INITIALIZING STORE WITH SAMPLE DATA ===\n");

    // Додавання товарів
    Product p1, p2, p3, p4, p5;
    product_init(&p1, "Apple", 1.5, 0.8, 50);
    product_init(&p2, "Bread", 2.0, 1.0, 30);
    product_init(&p3, "Milk", 3.0, 1.5, 20);
    product_init(&p4, "Cheese", 5.0, 3.0, 15);
    product_init(&p5, "Chocolate", 4.5, 2.5, 25);

    store_add_product(store, &p1);
    store_add_product(store, &p2);
    store_add_product(store, &p3);
    store_add_product(store, &p4);
    store_add_product(store, &p5);

    // Додавання продавців
    Seller s1, s2, s3;
    seller_init(&s1, "Alice Smith", "alice@store.com");
    seller_init(&s2, "Bob Johnson", "bob@store.com");
    seller_init(&s3, "Carol Williams", "carol@store.com");

    store_add_seller(store, &s1);
    store_add_seller(store, &s2);
    store_add_seller(store, &s3);

    // Додавання покупців
    Buyer b1, b2, b3, b4;
    buyer_init(&b1, "Charlie Brown", "charlie@email.com", 0.0, false);
    buyer_init(&b2, "Diana Prince", "diana@email.com", 0.1, true);
    buyer_init(&b3, "Bruce Wayne", "bruce@wayne.com", 0.15, true);
    buyer_init(&b4, "Clark Kent", "clark@dailyplanet.com", 0.05, false);

    store_add_buyer(store, &b1);
    store_add_buyer(store, &b2);
    store_add_buyer(store, &b3);
    store_add_buyer(store, &b4);

    printf("Store initialized with sample data:\n");
    printf("- 5 products\n");
    printf("- 3 sellers\n");
    printf("- 4 buyers\n");
}

void manual_data_input(Store* store) {
    printf("\n=== MANUAL DATA INPUT ===\n");

    // Введення товарів
    printf("\n--- PRODUCTS INPUT ---\n");
    int productCount = get_int_input("How many products do you want to add? ");

    for (int i = 0; i < productCount; i++) {
        printf("\nProduct #%d:\n", i + 1);
        char name[100], priceStr[20], costStr[20], quantityStr[20];

        get_string_input("Product name: ", name, sizeof(name));
        double price = get_double_input("Price: ");
        double cost = get_double_input("Cost: ");
        int quantity = get_int_input("Quantity: ");

        Product product;
        product_init(&product, name, price, cost, quantity);
        store_add_product(store, &product);
        printf("Product '%s' added successfully! Profit per item: %.2f USD\n",
               name, price - cost);
    }

    // Введення продавців
    printf("\n--- SELLERS INPUT ---\n");
    int sellerCount = get_int_input("How many sellers do you want to add? ");

    for (int i = 0; i < sellerCount; i++) {
        printf("\nSeller #%d:\n", i + 1);
        char name[100], contact[100];

        get_string_input("Seller name: ", name, sizeof(name));
        get_string_input("Contact: ", contact, sizeof(contact));

        Seller seller;
        seller_init(&seller, name, contact);
        store_add_seller(store, &seller);
        printf("Seller '%s' added successfully!\n", name);
    }

    // Введення покупців
    printf("\n--- BUYERS INPUT ---\n");
    int buyerCount = get_int_input("How many buyers do you want to add? ");

    for (int i = 0; i < buyerCount; i++) {
        printf("\nBuyer #%d:\n", i + 1);
        char name[100], contact[100];

        get_string_input("Buyer name: ", name, sizeof(name));
        get_string_input("Contact: ", contact, sizeof(contact));
        double discount = get_double_input("Discount (0-1): ");
        char regular = get_char_input("Regular customer? (y/n): ");

        Buyer buyer;
        buyer_init(&buyer, name, contact, discount, (regular == 'y' || regular == 'Y'));
        store_add_buyer(store, &buyer);
        printf("Buyer '%s' added successfully!\n", name);
    }

    printf("\nManual data input completed!\n");
}

void manual_purchases_input(Store* store) {
    printf("\n=== MANUAL PURCHASES INPUT ===\n");

    int purchaseCount = get_int_input("How many purchase sessions do you want to enter? ");

    for (int i = 0; i < purchaseCount; i++) {
        printf("\n--- Purchase Session #%d ---\n", i + 1);
        store_manual_purchase_input(store);
    }

    printf("\nManual purchases input completed!\n");
}

void simulate_day(Store* store, int day, bool automaticMode) {
    printf("\n\n=== DAY %d SIMULATION ===\n", day);

    if (automaticMode) {
        // Випадкові покупки тільки в автоматичному режимі
        printf("\n1. Simulating customer purchases...\n");
        int transactions = 10 + (rand() % 15);
        store_simulate_random_purchases(store, transactions);

        // Випадкове поповнення запасів
        printf("\n2. Restocking products...\n");
        int restocks = 2 + (rand() % 4);
        for (int i = 0; i < restocks; i++) {
            store_simulate_random_restocking(store);
        }
    } else {
        // В ручному режимі - тільки розрахунок зарплат
        printf("\nProcessing daily operations...\n");
    }

    // Розрахунок зарплат
    printf("\n3. Calculating salaries...\n");
    store_calculate_salaries(store, 0.05);

    // Показ результатів дня
    printf("\n4. End of day report:\n");
    store_display_financial_report(store);
}

    bool check_if_data_exists(void) {
        FILE* productFile = fopen("products.bin", "rb");
        FILE* sellerFile = fopen("sellers.bin", "rb");
        FILE* buyerFile = fopen("buyers.bin", "rb");
        FILE* balanceFile = fopen("balance.bin", "rb");
        FILE* managerFile = fopen("manager.bin", "rb");

        bool exists = (productFile != NULL) || (sellerFile != NULL) ||
                      (buyerFile != NULL) || (balanceFile != NULL) ||
                      (managerFile != NULL);

        if (productFile) fclose(productFile);
        if (sellerFile) fclose(sellerFile);
        if (buyerFile) fclose(buyerFile);
        if (balanceFile) fclose(balanceFile);
        if (managerFile) fclose(managerFile);

        return exists;

}