#include <stdio.h>

int main() {
    unsigned int n;
    
    printf("Enter 32-bit natural number: ");
    scanf("%u", &n);
    
    printf("\nOriginal number:\n");
    printf("Decimal: %u\n", n);
    printf("Hexadecimal: 0x%x\n", n);

    unsigned int first_8_bits = (n >> 24) & 0xFF;

    unsigned int last_8_bits = n & 0xFF;

    unsigned int middle_16_bits = n & 0x00FFFF00;

    unsigned int result = middle_16_bits | (last_8_bits << 24) | first_8_bits;
    
    printf("\nResult after swapping bits:\n");
    printf("Decimal: %u\n", result);
    printf("Hexadecimal: 0x%x\n", result);
    
    return 0;
}