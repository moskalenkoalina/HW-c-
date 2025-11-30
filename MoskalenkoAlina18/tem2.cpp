#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    
    Node* top_ptr;
    int stack_size;

public:
    Stack() {
        top_ptr = nullptr;
        stack_size = 0;
    }
    
    Stack(const Stack& other) {
        top_ptr = nullptr;
        stack_size = 0;
        if(other.top_ptr != nullptr) {
            Stack temp;
            Node* curr = other.top_ptr;
            while(curr != nullptr) {
                temp.push(curr->data);
                curr = curr->next;
            }
            while(!temp.empty()) {
                push(temp.top());
                temp.pop();
            }
        }
    }
    
    Stack& operator=(const Stack& other) {
        if(this != &other) {
            while(!empty()) pop();
            
            if(!other.empty()) {
                Stack temp;
                Node* curr = other.top_ptr;
                while(curr != nullptr) {
                    temp.push(curr->data);
                    curr = curr->next;
                }
                while(!temp.empty()) {
                    push(temp.top());
                    temp.pop();
                }
            }
        }
        return *this;
    }
    
    ~Stack() {
        while(!empty()) pop();
    }
    
    void push(const T& val) {
        Node* new_node = new Node(val);
        new_node->next = top_ptr;
        top_ptr = new_node;
        stack_size++;
    }
    
    void pop() {
        if(empty()) throw runtime_error("empty stack");
        Node* temp = top_ptr;
        top_ptr = top_ptr->next;
        delete temp;
        stack_size--;
    }
    
    T& top() {
        if(empty()) throw runtime_error("empty stack");
        return top_ptr->data;
    }
    
    const T& top() const {
        if(empty()) throw runtime_error("empty stack");
        return top_ptr->data;
    }
    
    bool empty() const {
        return top_ptr == nullptr;
    }
    
    int size() const {
        return stack_size;
    }
};

template<typename T>
int inputWithMyStack(T*& result_array) {
    Stack<T> my_stack;
    T num;
    
    cout << "Enter numbers (0 to stop):" << endl;
    
    while(true) {
        cin >> num;
        if(num == 0) break;
        my_stack.push(num);
    }
    
    int count = my_stack.size();
    if(count > 0) {
        result_array = new T[count];
        for(int i = 0; i < count; i++) {
            result_array[count-1-i] = my_stack.top();
            my_stack.pop();
        }
    } else {
        result_array = nullptr;
    }
    
    return count;
}

template<typename T>
int inputWithStdStack(T*& result_array) {
    stack<T> std_stack;
    T num;
    
    cout << "Enter numbers (0 to stop):" << endl;
    
    while(true) {
        cin >> num;
        if(num == 0) break;
        std_stack.push(num);
    }
    
    int count = std_stack.size();
    if(count > 0) {
        result_array = new T[count];
        for(int i = 0; i < count; i++) {
            result_array[count-1-i] = std_stack.top();
            std_stack.pop();
        }
    } else {
        result_array = nullptr;
    }
    
    return count;
}

template<typename T>
void showArray(T* arr, int n) {
    if(arr == nullptr || n == 0) {
        cout << "empty array" << endl;
        return;
    }
    
    cout << "Array (" << n << " elements): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ", ";
    }
    cout << endl;
}

void testWithInt() {
    
    cout << "\nMy Stack:" << endl;
    int* arr1 = nullptr;
    int n1 = inputWithMyStack(arr1);
    showArray(arr1, n1);
    delete[] arr1;

    cout << "\nSTL Stack:" << endl;
    int* arr2 = nullptr;
    int n2 = inputWithStdStack(arr2);
    showArray(arr2, n2);
    delete[] arr2;
}


void testStack() {
    
    Stack<int> s;
    
    cout << "push 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "size: " << s.size() << endl;
    cout << "top: " << s.top() << endl;
    
    cout << "pop all:" << endl;
    while(!s.empty()) {
        cout << "top: " << s.top() << ", size: " << s.size() << endl;
        s.pop();
    }
    
    cout << "empty: " << s.empty() << endl;
    
    try {
        s.top();
    }
}

int main() {
    testWithInt();
    testWithDouble();
    testStack();
    
    return 0;
}