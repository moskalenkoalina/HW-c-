#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double a_prev = 1.0;
    double t_prev = 1.0;
    double sum = 0.0;

    for (int k = 1; k <= n; k++) {

        double a_k = k * a_prev + 1.0 / k;

        double t_k = t_prev * (2.0 / k);

        double term = t_k * a_k;
        sum += term;

        a_prev = a_k;
        t_prev = t_k;
    }

    printf("S%d = %.6f\n", n, sum);

    return 0;
}