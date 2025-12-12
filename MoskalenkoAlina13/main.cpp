#include "Rational.h"
#include <stdio.h>

Rational findSmallestRational(Rational arr[], int size) {
    Rational min = arr[0];
    for (int i = 1; i < size; i++) {
        if (isLess(&arr[i], &min)) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    Rational numbers[] = {
        createRational(1, 2),
        createRational(3, 4),
        createRational(2, 5),
        createRational(7, 8)
    };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Rational min = findSmallestRational(numbers, size);
    printf("Smallest number: ");
    printRational(&min);
    printf("\n");

    Rational a = createRational(1, 3);
    Rational b = createRational(2, 5);

    Rational sum = addRational(&a, &b);
    Rational product = multiplyRational(&a, &b);

    printf("Sum: ");
    printRational(&sum);
    printf("\nProduct: ");
    printRational(&product);
    printf("\n");

    printf("a < b: %s\n", isLess(&a, &b) ? "Yes" : "No");

    return 0;
}
