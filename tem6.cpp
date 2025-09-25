#include <stdio.h>

int main() {
    double C, F;
    printf("enter the temperature in degrees Celsius:");
    scanf("%lf", &C);

    F = C * 9 / 5 + 32;
    printf("F=%.e\n", F);
    return 0;
}