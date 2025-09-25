#include <stdio.h>
#include <math.h>

int main() {
    float f1 = 1e-4;
    double d1 = 1e-4;
    long double ld1 = 1e-4;
    printf("%.2f\n", f1);
    printf("%.2f\n", d1);
    printf("%.2f\n", ld1);

    float f2 = 24.33e5;
    double d2 = 24.33e5;
    long double ld2 = 24.33e5;
    printf("%.2f\n", f2);
    printf("%.2f\n", d2);
    printf("%.2f\n", ld2);

    float f3 = M_PI;
    double d3 = M_PI;
    long double ld3 = M_PI;
    printf("%.2f\n", f3);
    printf("%.2f\n", d3);
    printf("%.2f\n", ld3);

    float f4 = sqrt(5);
    double d4 = sqrt(5);
    long double ld4 = sqrt(5);
    printf("%.2f\n", f4);
    printf("%.2f\n", d4);
    printf("%.2f\n", ld4);

    return 0;
}