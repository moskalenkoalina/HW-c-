#include <stdio.h>
#include <stdint.h>

uint16_t multiply_8bit(uint8_t a, uint8_t b) {
    return (uint16_t)a * (uint16_t)b;
}

int main() {
    uint8_t num1, num2;
    
    printf("enter number(0-255): ");
    scanf("%hhu", &num1);
    
    printf("enter number(0-255): ");
    scanf("%hhu", &num2);
    
    uint16_t result = multiply_8bit(num1, num2);
    
    printf(" %hhu * %hhu = %hu\n", num1, num2, result);

    uint8_t max_8bit = 255;
    uint16_t max_result = multiply_8bit(max_8bit, max_8bit);
    printf("result= %hu \n", max_result);
    
    return 0;
}