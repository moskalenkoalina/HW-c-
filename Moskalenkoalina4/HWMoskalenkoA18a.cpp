#include <stdio.h>

int main() {
    int n, k;
    double x, power, xk;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Sequence elements:\n");

    power = 1.0;
    for (k = 1; k <= n; k++) {
        power *= x;
        xk = power / k;
        printf("x%d = %.6f\n", k, xk);
    }

    return 0;
}