#include <stdio.h>

int main() {
    int a, b;

    printf("Enter numbers: ");
    scanf("%d %d", &a, &b);

    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;

    if (a == b) {
        printf("  %d = %d\n", a, b);
    } else {
        printf("A larger number: %d\n", max);
        printf("A smaller number: %d\n", min);
    }

    return 0;
}