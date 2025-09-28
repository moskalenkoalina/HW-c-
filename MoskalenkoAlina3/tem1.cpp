#include <stdio.h>

int main() {
    int n;

    do {
        printf("Enter n: ");
        scanf("%d", &n);

        if (n < 100 || n > 999) {
            printf("Error!!!\n");
        }
    } while (n < 100 || n > 999);

    int ones = n % 10;
    int tens = (n / 10) % 10;
    int hundreds = n / 100;

    printf("ones: %d, tens: %d, hundreds: %d\n", ones, tens, hundreds);

    int digit_sum = ones + tens + hundreds;
    printf(" Suma: %d\n", digit_sum);

    int reversed_num = ones * 100 + tens * 10 + hundreds;
    printf(" The number reversed: %d\n", reversed_num);

    return 0;
}

