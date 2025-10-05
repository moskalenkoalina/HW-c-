#include <stdio.h>

int main() {
    unsigned int n;
    
    printf("Enter a natural number: ");
    scanf("%u", &n);

    if (n != 0 && (n & (n - 1)) == 0) {
        printf("%u is a power of two\n", n);
    } else {
        printf("%u is NOT a power of two\n", n);
    }
    
    return 0;
}