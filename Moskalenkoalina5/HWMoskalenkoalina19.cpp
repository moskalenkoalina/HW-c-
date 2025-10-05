#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter a positive : ");
    scanf("%u", &n);

    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
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