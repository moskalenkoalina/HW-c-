#include <iostream>
#include <stack>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    stack<int> s;
    srand(time(0));
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Random numbers: ";
    for (int i = 0; i < n; i++) {
        int num = rand() % 100;
        s.push(num);
        cout << num << " ";
    }
    cout << endl;
    
    int arr[100];
    int size = 0;
    
    while (!s.empty()) {
        arr[size] = s.top();
        s.pop();
        size++;
    }
    
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
    
    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "\nSorting begins..." << endl;
    
    for (int i = size - 1; i >= 0; i--) {
        int* max_ptr = max_element(arr, arr + i + 1);
        int max_index = max_ptr - arr;
        swap(arr[max_index], arr[i]);
        
        cout << "Step " << size - i << ": ";
        for (int j = 0; j < size; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
