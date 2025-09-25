#include <cmath>
#include <stdio.h>

int main() {
    double x;
    printf("x= ");
    scanf("%lf", &x);

    double x2 = x*x;
    double x4 = x2*x2;
    printf("x^4=%.2f\n", x4);

    double x6 = x * x;
    x6 = x6 * x;
    x6 = x6 * x6;
    printf("x^6= %.2f\n", x6);

    double x9 = x * x;
    x9 = x9 * x9;
    x9 = x9 * x9;
    x9 = x9 * x;
    printf("x^9 = %.2f\n", x9);

    double x15 = x * x;
    x15 = x15 * x;
    x15 = x15 * x15;
    x15 = x15 * x15;
    x15 = x15 * x15;
    x15 = x * x;
    double x3 = x15 * x;
    x15 = x3 * x3;
    double x12 = x15 * x15;
    x15 = x12 * x3;
    printf("x^15 = %.2f\n", x15);


    double x64 = x * x;
    x64 = x64 * x64;
    x64 = x64 * x64;
    x64 = x64 * x64;
    x64 = x64 * x64;
    x64 = x64 * x64;
    printf("x^64 = %.2f\n", x64);

    return 0;
}