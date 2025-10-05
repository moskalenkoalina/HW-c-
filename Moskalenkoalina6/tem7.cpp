#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x;

    printf("Enter n=");
    scanf("%d", &n);
    printf("Enter x=");
    scanf("%lf", &x);

    if (n < 1) {
        printf("n must be at least 1\n");
        return 1;
    }

    double a_prev2, a_prev1, a_current;
    double b_prev2, b_prev1, b_current;
    double sum = 0.0;
    double x_power = x;

    if (n >= 1) {
        a_prev2 = 0.0;
        b_prev2 = 1.0;
        double term = x_power / (a_prev2 + b_prev2);
        sum += term;
        printf("k=1: term=%.6lf, sum=%.6lf\n", term, sum);
    }


    if (n >= 2) {
        a_prev1 = 1.0;
        b_prev1 = 0.0;
        x_power *= x;
        double term = x_power / (a_prev1 + b_prev1);
        sum += term;
        printf("k=2: term=%.6lf, sum=%.6lf\n", term, sum);
    }

    for (int k = 3; k <= n; k++) {
        x_power *= x;

        b_current = 0.0;
        a_current = a_prev1/k + a_prev2*b_current;

        double denominator = a_current + b_current;
        double term = x_power / denominator;
        sum += term;

        printf("k=%d: a=%.6lf, b=%.6lf, term=%.6lf, sum=%.6lf\n",
               k, a_current, b_current, term, sum);

        a_prev2 = a_prev1;
        a_prev1 = a_current;
        b_prev2 = b_prev1;
        b_prev1 = b_current;
    }

    printf("Final sum S_n = %.6lf\n", sum);

    return 0;
}