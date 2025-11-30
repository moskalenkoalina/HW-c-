#include "Rational.h"
#include <stdio.h>
#include <stdlib.h>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational createRational(int num, int den) {
    if (den == 0) {
        printf("Error!\n");
        exit(1);
    }

    int gcd = findGCD(abs(num), abs(den));
    num /= gcd;
    den /= gcd;

    if (den < 0) {
        num = -num;
        den = -den;
    }

    Rational r = {num, den};
    return r;
}

void printRational(Rational r) {
    if (r.denominator == 1) {
        printf("%d", r.numerator);
    } else {
        printf("%d/%d", r.numerator, r.denominator);
    }
}

Rational inputRational() {
    int num, den;

    printf("Enter numerator: ");
    scanf("%d", &num);

    printf("Enter denominator: ");
    scanf("%d", &den);

    return createRational(num, den);
}

Rational subtract(Rational a, Rational b) {
    int new_num = a.numerator * b.denominator - b.numerator * a.denominator;
    int new_den = a.denominator * b.denominator;
    return createRational(new_num, new_den);
}

Rational divide(Rational a, Rational b) {
    if (b.numerator == 0) {
        printf("Error!\n");
        exit(1);
    }
    return createRational(a.numerator * b.denominator, a.denominator * b.numerator);
}

void writeToFile(Rational r, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error!  %s!\n", filename);
        return;
    }

    if (r.denominator == 1) {
        fprintf(file, "%d", r.numerator);
    } else {
        fprintf(file, "%d/%d", r.numerator, r.denominator);
    }

    fclose(file);
    printf("fraction added to file %s\n", filename);
}