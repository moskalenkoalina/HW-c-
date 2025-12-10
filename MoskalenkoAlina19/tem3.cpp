#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
class Polynomial {
private:
    list<T> c;

public:
    Polynomial() {}

    Polynomial(const list<T>& a) : c(a) {
        normalize();
    }

    Polynomial(const vector<T>& a) {
        for (auto x : a) c.push_back(x);
        normalize();
    }

    Polynomial(T k) {
        c.push_back(k);
    }

    void normalize() {
        while (c.size() > 1 && c.back() == T(0)) {
            c.pop_back();
        }
    }

    size_t degree() const {
        return c.size() - 1;
    }

    T get(size_t p) const {
        if (p >= c.size()) return T(0);
        auto it = c.begin();
        advance(it, p);
        return *it;
    }

    void set(size_t p, T val) {
        if (p >= c.size()) {
            for (size_t i = c.size(); i <= p; i++) c.push_back(0);
        }
        auto it = c.begin();
        advance(it, p);
        *it = val;
        normalize();
    }

    void input() {
        c.clear();
        int d;
        cout << "Degree: ";
        cin >> d;
        cout << "Enter coefficients from constant term:\n";
        for (int i = 0; i <= d; i++) {
            T x;
            cout << "a[" << i << "] = ";
            cin >> x;
            c.push_back(x);
        }
        normalize();
    }

    void print() const {
        if (c.empty()) {
            cout << "0\n";
            return;
        }
        bool first = true;
        int p = 0;

        for (auto x : c) {
            if (x == 0 && p > 0) {
                p++;
                continue;
            }
            if (!first) {
                cout << (x >= 0 ? " + " : " - ");
            } else {
                if (x < 0) cout << "-";
            }

            T v = abs(x);
            if (p == 0) cout << v;
            else if (v == 1) cout << "x";
            else cout << v << "*x";

            if (p > 1) cout << "^" << p;

            first = false;
            p++;
        }
        cout << endl;
    }

    T operator()(T x) const {
        T s = 0, p = 1;
        for (auto a : c) {
            s += a * p;
            p *= x;
        }
        return s;
    }

    Polynomial operator+(const Polynomial& b) const {
        Polynomial r;
        size_t d = max(degree(), b.degree());
        for (size_t i = 0; i <= d; i++) {
            r.set(i, get(i) + b.get(i));
        }
        return r;
    }

    Polynomial operator*(const Polynomial& b) const {
        Polynomial r;
        for (size_t i = 0; i <= degree(); i++) {
            for (size_t j = 0; j <= b.degree(); j++) {
                r.set(i + j, r.get(i + j) + get(i) * b.get(j));
            }
        }
        return r;
    }
};

void demo() {
    Polynomial<double> p1, p2;

    cout << "Polynomial 1:\n";
    p1.input();

    cout << "Polynomial 2:\n";
    p2.input();

    cout << "\nP1 = ";
    p1.print();
    cout << "P2 = ";
    p2.print();

    Polynomial<double> s = p1 + p2;
    Polynomial<double> m = p1 * p2;

    cout << "\nSum: ";
    s.print();
    cout << "Product: ";
    m.print();

    double x;
    cout << "\nEnter x: ";
    cin >> x;

    cout << "P1(" << x << ") = " << p1(x) << endl;
    cout << "P2(" << x << ") = " << p2(x) << endl;
    cout << "Sum(" << x << ") = " << s(x) << endl;
    cout << "Product(" << x << ") = " << m(x) << endl;
}

int main() {
    demo();
    return 0;
}
