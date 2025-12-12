#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct {
    int nominator;
    unsigned denominator;
} Rational;

Rational createRationalDefault(void);
Rational createRational(int nom, unsigned den);

void inputRational(Rational *r);
void printRational(const Rational *r);

Rational addRational(const Rational *r1, const Rational *r2);
Rational multiplyRational(const Rational *r1, const Rational *r2);

int compareRational(const Rational *r1, const Rational *r2);
int isEqual(const Rational *r1, const Rational *r2);
int isLess(const Rational *r1, const Rational *r2);
int isGreater(const Rational *r1, const Rational *r2);

void setNominator(Rational *r, int nom);
void setDenominator(Rational *r, unsigned den);

void reduceFraction(Rational *r);
unsigned findGCD(unsigned a, unsigned b);

#endif