#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string surname;

public:
    Person() {}
    Person(string n, string s) : name(n), surname(s) {}

    virtual void input() {
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Surname: ";
        getline(cin, surname);
    }

    virtual void print() const {
        cout << "Name: " << name << ", Surname: " << surname;
    }

    string getName() const { return name; }
    string getSurname() const { return surname; }
};

class Passenger : public Person {
    string from;
    string to;
    int seat;

public:
    Passenger() : seat(0) {}
    Passenger(string n, string s, string f, string t, int st)
        : Person(n, s), from(f), to(t), seat(st) {}

    void input() override {
        Person::input();
        cout << "From: ";
        getline(cin, from);
        cout << "To: ";
        getline(cin, to);
        cout << "Seat number: ";
        cin >> seat;
    }

    void print() const override {
        Person::print();
        cout << ", From: " << from << ", To: " << to
             << ", Seat: " << seat << endl;
    }

    string getFrom() const { return from; }
    string getTo() const { return to; }
    int getSeat() const { return seat; }
};

class Kasa {
    vector<Passenger> passengers;
    string filename = "passengers.bin";

public:

    void writeString(ofstream &out, const string &s) {
        size_t len = s.size();
        out.write((char*)&len, sizeof(len));
        out.write(s.c_str(), len);
    }

    string readString(ifstream &in) {
        size_t len;
        if (!in.read((char*)&len, sizeof(len))) return "";
        if (len > 1000) len = 1000; 
        string s(len, '\0');
        in.read(&s[0], len);
        return s;
    }

    void writePassenger(ofstream &out, const Passenger &p) {
        writeString(out, p.getName());
        writeString(out, p.getSurname());
        writeString(out, p.getFrom());
        writeString(out, p.getTo());
        int seat = p.getSeat();
        out.write((char*)&seat, sizeof(seat));
    }

    Passenger readPassenger(ifstream &in) {
        string n = readString(in);
        string s = readString(in);
        string f = readString(in);
        string t = readString(in);
        int seat;
        if (!in.read((char*)&seat, sizeof(seat))) seat = 0;
        return Passenger(n, s, f, t, seat);
    }

    void saveAll() {
        ofstream out(filename, ios::binary);
        if (!out) {
            cout << "Cannot open file for writing!\n";
            return;
        }
        size_t count = passengers.size();
        out.write((char*)&count, sizeof(count));
        for (auto &p : passengers) writePassenger(out, p);
    }

    void loadAll() {
        passengers.clear();
        ifstream in(filename, ios::binary);
        if (!in || in.peek() == ifstream::traits_type::eof()) {
            cout << "File empty or not found. Starting with empty list.\n";
            return;
        }

        size_t count;
        if (!in.read((char*)&count, sizeof(count))) return;
        if (count > 1000) count = 1000;
        for (size_t i = 0; i < count; i++) {
            passengers.push_back(readPassenger(in));
        }
    }

    bool addPassenger(const Passenger &p) {
        for (auto &pass : passengers) {
            if (pass.getSeat() == p.getSeat()) {
                cout << "This seat is already taken!\n";
                return false;
            }
        }
        passengers.push_back(p);
        saveAll();
        return true;
    }

    void printAll() {
        for (auto &p : passengers) p.print();
    }

    void findBySurname(const string &s) {
        for (auto &p : passengers)
            if (p.getSurname() == s) p.print();
    }

    void findByFrom(const string &f) {
        for (auto &p : passengers)
            if (p.getFrom() == f) p.print();
    }

    void findByTo(const string &t) {
        for (auto &p : passengers)
            if (p.getTo() == t) p.print();
    }

    void findBySeat(int seat) {
        for (auto &p : passengers)
            if (p.getSeat() == seat) p.print();
    }

    int findFreeSeat(const vector<int> &allSeats) {
        for (int seat : allSeats) {
            bool busy = false;
            for (auto &p : passengers) {
                if (p.getSeat() == seat) {
                    busy = true;
                    break;
                }
            }
            if (!busy) return seat;
        }
        return -1;
    }
};

int main() {
    Kasa kasa;
    kasa.loadAll();

    Passenger p;
    while (true) {
        p.input();
        if (kasa.addPassenger(p)) break;
        cout << "Try again.\n";
    }

    cout << "\nAll passengers:\n";
    kasa.printAll();

    cout << "\nSearch by surname (enter surname): ";
    string s;
    cin.ignore();
    getline(cin, s);
    kasa.findBySurname(s);

    cout << "\nSearch by departure (from): ";
    string f;
    getline(cin, f);
    kasa.findByFrom(f);

    cout << "\nSearch by arrival (to): ";
    string t;
    getline(cin, t);
    kasa.findByTo(t);

    cout << "\nSearch by seat number: ";
    int seatNum;
    cin >> seatNum;
    kasa.findBySeat(seatNum);

    vector<int> seats = {1,2,3,4,5,6,7,8,9,10};
    int freeSeat = kasa.findFreeSeat(seats);

    if (freeSeat == -1)
        cout << "No free seats.\n";
    else
        cout << "First free seat: " << freeSeat << endl;

    return 0;
}




