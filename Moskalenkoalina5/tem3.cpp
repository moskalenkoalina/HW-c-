#include <stdio.h>

int main() {
    unsigned long long m;
    int j;

    printf("Enter 64-bit number m: ");
    scanf("%llu", &m);

    printf("Enter bit position j (0-63) to set to 0: ");
    scanf("%d", &j);

    if (j < 0 || j > 63) {
        printf("Error: Bit position must be between 0 and 63\n");
        return 1;
    }

    unsigned long long mask = ~(1ULL << j);
    unsigned long long result = m & mask;

    printf("Result in decimal: %llu\n", result);
    printf("Result in hexadecimal: %llx\n", result);

    return 0;
}