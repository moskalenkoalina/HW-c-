#include "toys.h"

using namespace std;

bool isToySuitableForAge(const Toy& toy, int age) {
    return age >= toy.min_age && age <= toy.max_age;
}

vector<Toy> readToysFromTextFile(const string& filename) {
    vector<Toy> toys;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return toys;
    }
    
    string line;
    while (getline(file, line)) {
        Toy toy;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            toy.name = line.substr(0, pos1);
            toy.price = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
            toy.min_age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            toy.max_age = stoi(line.substr(pos3 + 1));
            
            toys.push_back(toy);
        }
    }
    
    file.close();
    return toys;
}

vector<pair<Toy, Toy>> findToyPairs(const vector<Toy>& toys, int age, double max_total_price) {
    vector<pair<Toy, Toy>> results;
    vector<Toy> suitable_toys;
    
    for (const auto& toy : toys) {
        if (isToySuitableForAge(toy, age)) {
            suitable_toys.push_back(toy);
        }
    }
    
    for (size_t i = 0; i < suitable_toys.size(); ++i) {
        for (size_t j = i + 1; j < suitable_toys.size(); ++j) {
            if (suitable_toys[i].price + suitable_toys[j].price <= max_total_price) {
                results.push_back({suitable_toys[i], suitable_toys[j]});
            }
        }
    }
    
    return results;
}

void writeResultsToBinaryAndConsole(const vector<pair<Toy, Toy>>& results, 
                                   const string& filename, double max_price) {
    ofstream binFile(filename, ios::binary);
    
    if (!binFile.is_open()) {
        cerr << "Error: Cannot create binary file " << filename << endl;
        return;
    }
    
    cout << "\nSEARCH RESULTS" << endl;
    cout << "Found " << results.size() << " pair(s) of toys for the given criteria:" << endl;

    
    size_t count = results.size();
    binFile.write(reinterpret_cast<const char*>(&count), sizeof(count));
    
    for (size_t i = 0; i < results.size(); ++i) {
        const auto& pair = results[i];
        double total_price = pair.first.price + pair.second.price;
        
        binFile.write(reinterpret_cast<const char*>(&total_price), sizeof(total_price));
        
        size_t name1_len = pair.first.name.length();
        binFile.write(reinterpret_cast<const char*>(&name1_len), sizeof(name1_len));
        binFile.write(pair.first.name.c_str(), name1_len);
        
        binFile.write(reinterpret_cast<const char*>(&pair.first.price), sizeof(pair.first.price));
        
        size_t name2_len = pair.second.name.length();
        binFile.write(reinterpret_cast<const char*>(&name2_len), sizeof(name2_len));
        binFile.write(pair.second.name.c_str(), name2_len);
        
        binFile.write(reinterpret_cast<const char*>(&pair.second.price), sizeof(pair.second.price));
        
        cout << "Pair " << i + 1 << ":" << endl;
        cout << "  Toy 1: " << pair.first.name << " (" << pair.first.price << " UAH)" << endl;
        cout << "  Toy 2: " << pair.second.name << " (" << pair.second.price << " UAH)" << endl;
        cout << "  Total price: " << total_price << " UAH" << endl;
        cout << "  Age range: " << max(pair.first.min_age, pair.second.min_age) << 
                " - " << min(pair.first.max_age, pair.second.max_age) << " years" << endl;

    }
    
    binFile.close();
    cout << "Results also saved to binary file: " << filename << endl;
}

void createSampleFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Ball,150.50,2,5\n";
        file << "Doll,200.00,3,8\n";
        file << "Car,180.75,2,6\n";
        file << "Lego,350.00,4,12\n";
        file << "Puzzle,120.25,3,10\n";
        file << "Teddy Bear,250.00,1,5\n";
        file << "Robot,400.50,5,12\n";
        file << "Blocks,95.00,1,4\n";
        file.close();
        cout << "Sample file '" << filename << "' created with 8 toys." << endl;
    }
}