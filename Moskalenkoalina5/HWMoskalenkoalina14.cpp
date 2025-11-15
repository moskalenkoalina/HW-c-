#include <stdio.h>

int main() {
    unsigned int n;

    printf("Enter a natural number: ");
    scanf("%u", &n);

    if (n == 0) {
        printf("%u is NOT a power of two\n", n);
        return 0;
    }

    unsigned int temp = n;

    while (temp > 1) {
        if (temp & 1) {
            printf("%u is NOT a power of two\n", n);
            return 0;
        }
        temp >>= 1;
    }

    printf("%u is a power of two\n", n);
    return 0;
}