#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c;
    
    printf("Enter a, b and c: ");
    if (scanf("%d, %d, %d", &a, &b, &c) != 3) {
        printf("Error\n");
        return 1;
    }

    int limit_a = (int)pow(2, 10);
    if (abs(a) < limit_a && abs(b) < limit_a && abs(c) < limit_a) {
        int product = a * b * c;
        printf("result: %d * %d * %d = %d\n", a, b, c, product);
    } else {
        printf("\n 2^10 = %d The condition is not fulfilled\n", limit_a);

    }

    int limit_b = (int)pow(2, 21);
    if (abs(a) < limit_b && abs(b) < limit_b && abs(c) < limit_b) {
        long long product = (long long)a * b * c;
        printf("result: %d * %d * %d = %lld\n", a, b, c, product);
    } else {
        printf("\n 2^21= %d The condition is not fulfilled\n", limit_b);
    }
    
    return 0;
}