#include <stdio.h>

int main() {
    int n, result = 1;

    printf("Enter n: ");
    scanf("%d", &n);


    if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2) {
            result *= i;

        }
    }

    else {
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
    }

    printf("%d!! = %d\n", n, result);
    return 0;
}