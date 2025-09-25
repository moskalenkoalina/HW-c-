#include <stdio.h>

int main() {
    double a, b;
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    double arithmetic_mean = (a + b) / 2.0;

    double harmonic_mean = 2.0 * a * b / (a + b);

    printf("%.6f\n", arithmetic_mean);
    printf("%.6f\n", harmonic_mean);

    printf(" %e\n", arithmetic_mean);
    printf(" %e\n", harmonic_mean);
    
    return 0;
}