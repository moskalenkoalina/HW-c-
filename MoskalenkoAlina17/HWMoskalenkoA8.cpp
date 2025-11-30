#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

class PolynomialException : public exception {
private:
    string message;
public:
    PolynomialException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Polynomial {
private:
    int degree;
    vector<double> coefficients;

    void validateData(int deg, const vector<double>& coeffs) {
        if (deg < 0) {
            throw PolynomialException("I can't be negative.");
        }
        if (coeffs.size() != deg + 1) {
            throw PolynomialException("The number of coefficients does not match the degree of the polynomial");
        }
        for (size_t i = 0; i < coeffs.size(); ++i) {
            if (isnan(coeffs[i]) || isinf(coeffs[i])) {
                throw PolynomialException("coefficient " + to_string(i) + " is not a real number");
            }
        }
    }

public:
    Polynomial() : degree(0), coefficients({0.0}) {}

    Polynomial(int deg, const vector<double>& coeffs) {
        validateData(deg, coeffs);
        degree = deg;
        coefficients = coeffs;
    }

    Polynomial(const Polynomial& other) : degree(other.degree), coefficients(other.coefficients) {}

    void inputFromConsole() {
        try {
            cout << "Enter the degree of the polynomial: ";
            string degStr;
            getline(cin, degStr);

            int deg = stoi(degStr);
            if (deg < 0) {
                throw PolynomialException("The degree of a polynomial cannot be negative.");
            }

            vector<double> coeffs(deg + 1);
            cout << "enter " << deg + 1 << " coefficients (from a0 to a" << deg << "):" << endl;

            for (int i = 0; i <= deg; ++i) {
                cout << "a" << i << " = ";
                string coeffStr;
                getline(cin, coeffStr);

                try {
                    coeffs[i] = stod(coeffStr);
                    if (isnan(coeffs[i]) || isinf(coeffs[i])) {
                        throw PolynomialException("Invalid real number");
                    }
                } catch (const invalid_argument&) {
                    throw PolynomialException("coefficient " + to_string(i) + " is not real number");
                } catch (const out_of_range&) {
                    throw PolynomialException("Coefficient " + to_string(i) + " out of range");
                }
            }

            validateData(deg, coeffs);
            degree = deg;
            coefficients = coeffs;

        } catch (const PolynomialException& e) {
            throw;
        } catch (const exception& e) {
            throw PolynomialException("error: " + string(e.what()));
        }
    }

    void inputFromString(const string& input) {
        try {
            istringstream iss(input);
            string degStr;

            if (!(iss >> degStr)) {
                throw PolynomialException("Failed to read degree of polynomial");
            }

            int deg = stoi(degStr);
            if (deg < 0) {
                throw PolynomialException("Error! degree of the polynomial is negative");
            }

            vector<double> coeffs;
            double coeff;

            for (int i = 0; i <= deg; ++i) {
                if (!(iss >> coeff)) {
                    throw PolynomialException("Fill in the coefficients");
                }
                if (isnan(coeff) || isinf(coeff)) {
                    throw PolynomialException("coefficicent " + to_string(i) + " is a not real number");
                }
                coeffs.push_back(coeff);
            }

            validateData(deg, coeffs);
            degree = deg;
            coefficients = coeffs;

        } catch (const PolynomialException& e) {
            throw;
        } catch (const invalid_argument&) {
            throw PolynomialException("Incorrect number format in input string");
        } catch (const out_of_range&) {
            throw PolynomialException("The number in the input string is out of range.");
        }
    }

    void output() const {
        if (degree == 0 && coefficients[0] == 0) {
            cout << "0";
            return;
        }

        bool firstTerm = true;

        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (!firstTerm) {
                    cout << (coefficients[i] > 0 ? " + " : " - ");
                } else if (coefficients[i] < 0) {
                    cout << "-";
                }

                double absCoeff = abs(coefficients[i]);

                if (i == 0) {
                    cout << absCoeff;
                } else if (i == 1) {
                    if (absCoeff != 1) cout << absCoeff << "*";
                    cout << "x";
                } else {
                    if (absCoeff != 1) cout << absCoeff << "*";
                    cout << "x^" << i;
                }

                firstTerm = false;
            }
        }

        if (firstTerm) {
            cout << "0";
        }
    }

    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;

        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * power;
            power *= x;
        }

        return result;
    }

    Polynomial derivative() const {
        if (degree == 0) {
            return Polynomial(0, {0.0});
        }

        vector<double> derivCoeffs(degree);
        for (int i = 1; i <= degree; ++i) {
            derivCoeffs[i - 1] = coefficients[i] * i;
        }

        return Polynomial(degree - 1, derivCoeffs);
    }

    int getDegree() const { return degree; }
    vector<double> getCoefficients() const { return coefficients; }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        vector<double> resultCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }

        while (resultCoeffs.size() > 1 && resultCoeffs.back() == 0) {
            resultCoeffs.pop_back();
        }

        return Polynomial(resultCoeffs.size() - 1, resultCoeffs);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        vector<double> resultCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i) {
            resultCoeffs[i] -= other.coefficients[i];
        }

        while (resultCoeffs.size() > 1 && resultCoeffs.back() == 0) {
            resultCoeffs.pop_back();
        }

        return Polynomial(resultCoeffs.size() - 1, resultCoeffs);
    }

    Polynomial operator*(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        vector<double> resultCoeffs(resultDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultDegree, resultCoeffs);
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            degree = other.degree;
            coefficients = other.coefficients;
        }
        return *this;
    }
};

int main() {
    try {
        Polynomial p1;
        cout << "Enter data for the first polynomial:" << endl;
        p1.inputFromConsole();

        cout << "\nPolynomial from console: ";
        p1.output();
        cout << endl;

        double x;
        cout << "\nEnter x value to evaluate polynomial: ";
        cin >> x;
        cin.ignore();

        cout << "p(" << x << ") = " << p1.evaluate(x) << endl;

        Polynomial deriv = p1.derivative();
        cout << "Derivative: ";
        deriv.output();
        cout << endl;

    } catch (const PolynomialException& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    try {
        Polynomial p2;
        string input;

        cout << "Enter polynomial as string (format: degree coeff0 coeff1 ...):" << endl;
        cout << "For example: '2 1 2 3' for polynomial 3x^2 + 2x + 1" << endl;
        cout << "Your input: ";
        getline(cin, input);

        p2.inputFromString(input);

        cout << "Polynomial from string: ";
        p2.output();
        cout << endl;

        double x2;
        cout << "\nEnter x value to evaluate second polynomial: ";
        cin >> x2;
        cin.ignore();

        cout << "p2(" << x2 << ") = " << p2.evaluate(x2) << endl;

        Polynomial deriv2 = p2.derivative();
        cout << "Derivative of second polynomial: ";
        deriv2.output();
        cout << endl;

    } catch (const PolynomialException& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    try {
        Polynomial p1(2, {1.0, 2.0, 3.0});
        Polynomial p2(1, {2.0, 1.0});

        cout << "Predefined polynomial p1: ";
        p1.output();
        cout << endl;

        cout << "Predefined polynomial p2: ";
        p2.output();
        cout << endl;

        Polynomial sum = p1 + p2;
        cout << "p1 + p2: ";
        sum.output();
        cout << endl;

        Polynomial diff = p1 - p2;
        cout << "p1 - p2: ";
        diff.output();
        cout << endl;

        Polynomial prod = p1 * p2;
        cout << "p1 * p2: ";
        prod.output();
        cout << endl;

    } catch (const PolynomialException& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    try {
        Polynomial p(-1, {1.0});
    } catch (const PolynomialException& e) {
        cerr << "Creation error: " << e.what() << endl;
    }

    try {
        Polynomial p;
        p.inputFromString("-2 1 2");
    } catch (const PolynomialException& e) {
        cerr << "Input error: " << e.what() << endl;
    }

    return 0;
}