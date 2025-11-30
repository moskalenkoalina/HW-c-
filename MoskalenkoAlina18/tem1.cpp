#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace MyMath {
    template<typename T>
    T findMax(const T& a, const T& b) {
        return (a > b) ? a : b;
    }

    template<>
    string findMax<string>(const string& a, const string& b) {
        return (a > b) ? a : b;
    }

    class Rational {
    private:
        int numerator;
        int denominator;

        int gcd(int a, int b) const {
            a = abs(a);
            b = abs(b);
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        void simplify() {
            if (denominator == 0) {
                throw invalid_argument("The denominator cannot be zero.");
            }

            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }

            int common = gcd(numerator, denominator);
            numerator /= common;
            denominator /= common;
        }

    public:
        Rational() : numerator(0), denominator(1) {}
        Rational(int num) : numerator(num), denominator(1) {}
        Rational(int num, int den) : numerator(num), denominator(den) {
            simplify();
        }

        bool operator>(const Rational& other) const {
            return numerator * other.denominator > other.numerator * denominator;
        }

        bool operator<(const Rational& other) const {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator==(const Rational& other) const {
            return numerator * other.denominator == other.numerator * denominator;
        }

        bool operator!=(const Rational& other) const {
            return !(*this == other);
        }

        bool operator>=(const Rational& other) const {
            return !(*this < other);
        }

        bool operator<=(const Rational& other) const {
            return !(*this > other);
        }

        Rational operator+(const Rational& other) const {
            int new_num = numerator * other.denominator + other.numerator * denominator;
            int new_den = denominator * other.denominator;
            return Rational(new_num, new_den);
        }

        Rational operator-(const Rational& other) const {
            int new_num = numerator * other.denominator - other.numerator * denominator;
            int new_den = denominator * other.denominator;
            return Rational(new_num, new_den);
        }

        Rational operator*(const Rational& other) const {
            int new_num = numerator * other.numerator;
            int new_den = denominator * other.denominator;
            return Rational(new_num, new_den);
        }

        Rational operator/(const Rational& other) const {
            if (other.numerator == 0) {
                throw invalid_argument("/0");
            }
            int new_num = numerator * other.denominator;
            int new_den = denominator * other.numerator;
            return Rational(new_num, new_den);
        }

        friend ostream& operator<<(ostream& os, const Rational& r) {
            if (r.denominator == 1) {
                os << r.numerator;
            } else {
                os << r.numerator << "/" << r.denominator;
            }
            return os;
        }

        friend istream& operator>>(istream& is, Rational& r) {
            char slash;
            is >> r.numerator;

            if (is.peek() == '/') {
                is >> slash >> r.denominator;
            } else {
                r.denominator = 1;
            }
            
            r.simplify();
            return is;
        }

        int getNumerator() const { return numerator; }
        int getDenominator() const { return denominator; }
    };
}

void demonstrateFindMax() {
    using namespace MyMath;

    int a = 10, b = 20;
    cout << "findMax(" << a << ", " << b << ") = " << findMax(a, b) << endl;

    double x = 3.14, y = 2.71;
    cout << "findMax(" << x << ", " << y << ") = " << findMax(x, y) << endl;

    string s1 = "apple", s2 = "banana";
    cout << "findMax(\"" << s1 << "\", \"" << s2 << "\") = \"" << findMax(s1, s2) << "\"" << endl;

    Rational r1(1, 2), r2(3, 4);
    cout << "findMax(" << r1 << ", " << r2 << ") = " << findMax(r1, r2) << endl;

    Rational r3(5, 6), r4(2, 3);
    cout << "findMax(" << r3 << ", " << r4 << ") = " << findMax(r3, r4) << endl;

    Rational r5(-1, 3), r6(1, 4);
    cout << "findMax(" << r5 << ", " << r6 << ") = " << findMax(r5, r6) << endl;
}

void demonstrateRationalClass() {
    using namespace MyMath;

    Rational r1(1, 2);
    Rational r2(3, 4);

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;

    cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
    cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;
    cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
    cout << r1 << " / " << r2 << " = " << (r1 / r2) << endl;

    cout << r1 << " > " << r2 << " : " << (r1 > r2) << endl;
    cout << r1 << " < " << r2 << " : " << (r1 < r2) << endl;
    cout << r1 << " == " << r2 << " : " << (r1 == r2) << endl;
    cout << r1 << " != " << r2 << " : " << (r1 != r2) << endl;

    cout << "\nEnter a rational number : ";
    Rational r3;
    cin >> r3;
    cout << "You entered: " << r3 << endl;
}

int main() {
    demonstrateFindMax();
    demonstrateRationalClass();
    
    return 0;
}