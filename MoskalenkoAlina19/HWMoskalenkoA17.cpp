#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    list<int> numbers;
    int n, value;
    
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        numbers.push_back(value);
    }
    
    cout << "\nInitial list: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it != 0) {
            it = numbers.insert(it, -1);
            ++it;
        }
    }
    
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it == 2) {
            ++it;
            it = numbers.insert(it, 0);
        }
    }
    
    cout << "Resulting list: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
