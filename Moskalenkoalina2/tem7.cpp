#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C, r;

    printf("Enter angles: ");
    scanf("%lf %lf %lf", &A, &B, &C);

    printf("Enter r: ");
    scanf("%lf", &r);

    if (A <= 0 || B <= 0 || C <= 0) {
        printf("Angles must be positive!\n");
        return 1;
    }

    if (r <= 0) {
        printf("Radius must be positive!\n");
        return 1;
    }

    double p = M_PI / 180.0;

    double ctgA = cos(A/2 * p) / sin(A/2 * p);
    double ctgB = cos(B/2 * p) / sin(B/2 * p);
    double ctgC = cos(C/2 * p) / sin(C/2 * p);

    double area = r * r * (ctgA + ctgB + ctgC);


    printf("Area: S=%.2f\n", area);
    
    return 0;
}