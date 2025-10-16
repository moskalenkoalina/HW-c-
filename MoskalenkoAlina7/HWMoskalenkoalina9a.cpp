#include <stdio.h>

int main() {
    int n;
    double max, current;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error (n >= 1)\n");
        return 1;
    }

    printf("Enter number 1: ");
    scanf("%lf", &max);

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &current);

        if (current > max) {
            max = current;
        }
    }

    printf("maximum: %.2lf\n", max);

    return 0;
}