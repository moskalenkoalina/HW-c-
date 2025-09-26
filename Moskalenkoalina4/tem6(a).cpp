#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double result = 0.0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        result = sqrt(2 + result);
    }

    printf("Result: %.6f\n", result);
    return 0;
}