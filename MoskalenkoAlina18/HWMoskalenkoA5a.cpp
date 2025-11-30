#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Array {
private:
    T* data;
    int size;

public:
    Array() {
        data = nullptr;
        size = 0;
    }

    Array(int n) {
        size = n;
        data = new T[size];
    }

    Array(const Array& other) {
        size = other.size;
        data = new T[size];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for(int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void setSize(int newSize) {
        delete[] data;
        size = newSize;
        data = new T[size];
    }

    void input() {
        cout << "Enter " << size << " elements: ";
        for(int i = 0; i < size; i++) {
            cin >> data[i];
        }
    }

    void print() const {
        cout << "Array: ";
        for(int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort() {
        for(int i = 0; i < size-1; i++) {
            for(int j = 0; j < size-i-1; j++) {
                if(data[j] > data[j+1]) {
                    swap(data[j], data[j+1]);
                }
            }
        }
    }

    static void bubbleSortInPlace(T arr[], int n) {
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};

int main() {

    Array<int> arr1(5);
    cout << "Enter 5 integers: ";
    arr1.input();


    cout << "\nOriginal array:" << endl;
    arr1.print();

    arr1.bubbleSort();
    cout << "After bubble sort:" << endl;
    arr1.print();

    double numbers[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    int n = 5;

    cout << "Original static array: ";
    for(int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    Array<double>::bubbleSortInPlace(numbers, n);

    cout << "After static bubble sort: ";
    for(int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    Array<string> arr2(4);
    
    cout << "Enter 4 strings:" << endl;
    arr2.input();
    
    cout << "\nOriginal string array:" << endl;
    arr2.print();
    
    arr2.bubbleSort();
    cout << "After bubble sort:" << endl;
    arr2.print();
    
    return 0;
}