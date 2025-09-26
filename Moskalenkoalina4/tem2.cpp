#include <stdio.h>
#include <math.h>
int main() {
    unsigned n;
    printf("n=");
    scanf("%u", &n);
    printf("n=%u\n", n);

    for (unsigned i=n-1; i>0; i--) {
        printf("n=%u\n", i);
    }
}