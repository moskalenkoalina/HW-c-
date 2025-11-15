#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n;
    double numbers[MAX_SIZE];

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: n must be between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    double max = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Maximum: %.2lf\n", max);
    return 0;
}