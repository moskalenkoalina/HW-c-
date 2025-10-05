#include <stdio.h>

int main() {
    unsigned int n;
    
    printf("Enter a number: ");
    scanf("%u", &n);
    
    printf("Original number: %u (0x%x)\n", n, n);
    
    int maxConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;
    
    while (n) {
        if (n & 1) {
            currentConsecutiveOnes++;
            if (currentConsecutiveOnes > maxConsecutiveOnes) {
                maxConsecutiveOnes = currentConsecutiveOnes;
            }
        } else {
            currentConsecutiveOnes = 0;
        }
        n >>= 1;
    }
    
    printf("Maximum consecutive 1 bits: %d\n", maxConsecutiveOnes);
    
    return 0;
}