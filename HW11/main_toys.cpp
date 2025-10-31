#include "toys.h"

using namespace std;

void displayMenu() {
    cout << "\n=== TOY SEARCH PROGRAM ===" << endl;
    cout << "1. Load toys from text file" << endl;
    cout << "2. Search for toy pairs" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    vector<Toy> toys;
    string inputFilename;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter input text filename: ";
                cin >> inputFilename;
                
                toys = readToysFromTextFile(inputFilename);
                
                if (toys.empty()) {
                    cout << "File not found or empty. Would you like to create a sample file? (y/n): ";
                    char createChoice;
                    cin >> createChoice;
                    
                    if (createChoice == 'y' || createChoice == 'Y') {
                        createSampleFile(inputFilename);
                        toys = readToysFromTextFile(inputFilename);
                    }
                }
                
                if (!toys.empty()) {
                    cout << "Successfully loaded " << toys.size() << " toys." << endl;
                    cout << "\nLoaded toys:" << endl;
                    for (const auto& toy : toys) {
                        cout << toy.name << " | Price: " << toy.price << " UAH | Age: " 
                             << toy.min_age << "-" << toy.max_age << " years" << endl;
                    }
                }
                break;
            }
            
            case 2: {
                if (toys.empty()) {
                    cout << "Please load toys first (option 1)." << endl;
                    break;
                }
                
                int age;
                double max_price;
                string outputFilename;
                
                cout << "Enter child's age (X): ";
                cin >> age;
                
                cout << "Enter maximum total price (Y): ";
                cin >> max_price;
                
                cout << "Enter output binary filename: ";
                cin >> outputFilename;
                
                auto results = findToyPairs(toys, age, max_price);
                writeResultsToBinaryAndConsole(results, outputFilename, max_price);
                break;
            }
            
            case 3:
                cout << "Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}