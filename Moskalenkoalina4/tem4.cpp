#include <stdio.h>

int main() {
    int n;
    double x, sum = 0.0;

    printf("Enter n number: ");
    scanf("%d", &n);

    printf("Enter x: ");
    scanf("%lf", &x);

    for(int i = 1; i <= n; i++) {
        double term = i;

        for (int j = 1; j <= i; j++) {
            term *= x;
        }

        printf("%d * x^%d = %lf\n", i, i, term);
        sum += term;
    }

    printf("The sum is %lf\n", sum);
    return 0;
}