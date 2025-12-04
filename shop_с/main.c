/*
File: main.c
Main program file with menu and store simulation.
Done by Moskalenko Alina
Group: 2nd year, computer mathematics
Date 30.11.2025
*/


#include "store.h"
#include <unistd.h>
#include <ctype.h>

int main() {
    printf("=== STORE MANAGEMENT SYSTEM ===\n");
    printf("C Version with File Storage\n\n");

    // Перевіряємо наявність даних
    bool hasExistingData = check_if_data_exists();

    Manager manager;
    Store store;

    if (hasExistingData) {
        printf("Found existing data in binary files.\n");
        char useExisting = get_char_input("Do you want to use existing data? (y/n): ");

        if (useExisting == 'y' || useExisting == 'Y') {
            // Завантажуємо існуючі дані
            manager_init(&manager, "John Doe", "john.doe@store.com");
            store_init(&store, &manager, 15000.0);
            printf("Data loaded from files successfully.\n");
        } else {
            // Створюємо новий магазин
            manager_init(&manager, "John Doe", "john.doe@store.com");
            store_init(&store, &manager, 15000.0);
            store_clear_data(&store);
            printf("Starting with new data.\n");
            hasExistingData = false;
        }
    } else {
        // Створюємо новий магазин
        manager_init(&manager, "John Doe", "john.doe@store.com");
        store_init(&store, &manager, 15000.0);
        printf("No existing data found. Starting with new store.\n");
    }

    // Якщо немає даних, пропонуємо вибір заповнення
    if (!hasExistingData) {
        printf("\nChoose data input method:\n");
        printf("A - Automatic (sample data)\n");
        printf("M - Manual (enter data yourself)\n");

        char choice;
        do {
            choice = get_char_input("Enter your choice (A/M): ");
            choice = toupper(choice);
        } while (choice != 'A' && choice != 'M');

        if (choice == 'A') {
            initialize_store_with_sample_data(&store);
            printf("Sample data loaded successfully.\n");
        } else {
            manual_data_input(&store);
            printf("Manual data input completed.\n");
        }
    }

    sleep(2);

    // Показ початкового стану
    printf("\n\n=== INITIAL STORE STATE ===\n");
    store_display_status(&store);
    store_display_products(&store);
    store_display_sellers(&store);
    store_display_buyers(&store);

    sleep(3);

    // Запит на ручне введення покупок
    char purchaseChoice = get_char_input("\nDo you want to enter purchases manually? (y/n): ");

    if (purchaseChoice == 'y' || purchaseChoice == 'Y') {
        store_manual_purchase_input(&store);

        printf("\n=== STORE STATE AFTER MANUAL PURCHASES ===\n");
        store_display_status(&store);
        store_display_financial_report(&store);
        sleep(3);
    }

    // Симуляція днів роботи
    int days = get_int_input("\nEnter number of days to simulate: ");

    for (int day = 1; day <= days; day++) {
        simulate_day(&store, day, true); // true для автоматичного режиму
        sleep(2);
    }

    // Фінальний звіт
    printf("\n\n=== FINAL RESULTS ===\n");
    store_display_status(&store);
    store_display_financial_report(&store);

    printf("\n=== SIMULATION COMPLETED ===\n");
    printf("Simulated %d days of store operation.\n", days);
    printf("Final balance: %.2f USD\n", store.balance);

    // Зберігаємо дані при виході
    store_save_to_binary_file(&store);
    printf("All data saved to binary files.\n");

    // Очищаємо пам'ять
    store_destroy(&store);

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}