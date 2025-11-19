#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    unsigned byear;

public:
    Person() : name(""), byear(0) {}

    int input();
    void show();

    string get_name() { return name; }
};

int Person::input() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter year: ";
    cin >> byear;
    return 0;
}


void Person::show() {
    cout << "name: " << name << " year: " << byear << endl;
}


class Friend : public Person {
protected:
    string phone;

public:
    Friend() : Person(), phone("") {}

    Friend(string name_, unsigned byear_, string phone_) {
        name = name_;
        byear = byear_;
        phone = phone_;
    }

    string get_phone() { return phone; }
    void set_phone(string a) { phone = a; }

    void input() {
        Person::input();
        cout << "Enter phone: ";
        cin >> phone;
    }

};


class PhoneBook {
    Friend data[100];
    unsigned n;

public:
    PhoneBook() : n(0) {}

    void add_friend(Friend& f);
    string search_friend(string name);
};

void PhoneBook::add_friend(Friend& f) {
    if (n < 100) {
        data[n] = f;
        n++;
    }
}

string PhoneBook::search_friend(string name) {
    for (int i = 0; i < n; i++) {
        if (data[i].get_name() == name)
            return data[i].get_phone();
    }
    return "NOT FOUND";
}


int main() {
    PhoneBook PB;
    Friend R[100];
    string num;

    int count_friends;
    cout << "How many friends? ";
    cin >> count_friends;

    for (int i = 0; i < count_friends; i++) {
        cout << "\nFriend " << i + 1 << endl;
        R[i].input();
        PB.add_friend(R[i]);
    }


    cout << "Enter surname to search: ";
    cin >> num;

    cout << PB.search_friend(num) << endl;

    return 0;
}
