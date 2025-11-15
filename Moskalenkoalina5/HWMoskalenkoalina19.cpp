#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter a positive number: ");
    scanf("%u", &n);

    printf("Binary representation: ");

    int start_bit = 31;
    while (start_bit > 0 && ((n >> start_bit) & 1) == 0) {
        start_bit--;
    }

    for (int i = start_bit; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");

    int count = 0;
    unsigned int temp = n;

    while (temp >= 3) {
        if ((temp & 3) == 3) {
            count++;
        }
        temp >>= 1;
    }

    printf("Number of '11' occurrences: %d\n", count);
    return 0;
}