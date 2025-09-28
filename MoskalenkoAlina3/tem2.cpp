#include <stdio.h>

int main() {
    int n;

    do {
        printf("Enter n (100-999): ");
        scanf("%d", &n);
    } while (n < 100 || n > 999);

    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;

    if (a != b && a != c && b != c) {
        printf("Result  %d, %d, %d:\n", a, b, c);

        printf("%d%d%d\n", a, b, c);
        printf("%d%d%d\n", a, c, b);
        printf("%d%d%d\n", b, a, c);
        printf("%d%d%d\n", b, c, a);
        printf("%d%d%d\n", c, a, b);
        printf("%d%d%d\n", c, b, a);
    } else {
        printf("Including %d not all numbers are different.\n", n);
    }
    
    return 0;
}