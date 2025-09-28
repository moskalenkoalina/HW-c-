#include <stdio.h>
#include <math.h>

double calculate(double x) {
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;
    return x4 + x3 +x2 +x +1;
}

int main() {
    double x;


    printf("Enter x: ");
    scanf("%lf", &x);

    double y = calculate(x);

    printf("%.2f\n", y);
    return 0;
}