#include "Rational.h"
#include <stdio.h>

unsigned findGCD(unsigned a, unsigned b) {
    while (b != 0) {
        unsigned temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational createRationalDefault(void) {
    Rational r = {1, 1};
    return r;
}

Rational createRational(int nom, unsigned den) {
    Rational r = {nom, (den == 0) ? 1 : den};
    reduceFraction(&r);
    return r;
}

void inputRational(Rational *r) {
    printf("Enter numerator: ");
    scanf("%d", &r->nominator);

    do {
        printf("Enter denominator (non-zero): ");
        scanf("%u", &r->denominator);
    } while (r->denominator == 0);

    reduceFraction(r);
}

void printRational(const Rational *r) {
    printf("%d/%u", r->nominator, r->denominator);
}

Rational addRational(const Rational *r1, const Rational *r2) {
    Rational result = {
        r1->nominator * (int)r2->denominator + r2->nominator * (int)r1->denominator,
        r1->denominator * r2->denominator
    };
    reduceFraction(&result);
    return result;
}

Rational multiplyRational(const Rational *r1, const Rational *r2) {
    Rational result = {
        r1->nominator * r2->nominator,
        r1->denominator * r2->denominator
    };
    reduceFraction(&result);
    return result;
}

int compareRational(const Rational *r1, const Rational *r2) {
    int left = r1->nominator * (int)r2->denominator;
    int right = r2->nominator * (int)r1->denominator;
    return (left > right) - (left < right);
}

int isEqual(const Rational *r1, const Rational *r2) {
    return compareRational(r1, r2) == 0;
}

int isLess(const Rational *r1, const Rational *r2) {
    return compareRational(r1, r2) < 0;
}

int isGreater(const Rational *r1, const Rational *r2) {
    return compareRational(r1, r2) > 0;
}

void setNominator(Rational *r, int nom) {
    r->nominator = nom;
    reduceFraction(r);
}

void setDenominator(Rational *r, unsigned den) {
    r->denominator = (den == 0) ? 1 : den;
    reduceFraction(r);
}

void reduceFraction(Rational *r) {
    unsigned gcd = findGCD(
        (r->nominator < 0) ? -r->nominator : r->nominator,
        r->denominator
    );
    r->nominator /= (int)gcd;
    r->denominator /= gcd;
}
