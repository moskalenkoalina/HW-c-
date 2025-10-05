#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


void task2();

int main() {
    task2();
    return 0;
}

void task2() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    unsigned int k;
    printf("Enter k: ");
    scanf("%u", &k);

    int res = n| (1<<k);
    printf("Result: %d\n", res);


}

void task3() {
    int k;
    unsigned long long n,m;
    printf("Enter n: ");
    scanf("%u", &n);
    printf("Enter k: ");
    scanf("%u", &k);

    m = n & ~(1UL<<k);
    printf("%x or %d", m, m);
}
void task4() {
    uint32_t n, m;
    printf("Enter n: ");
    scanf_s("% SCNu32", &n);

    uint32_t b0 = n & 0xFFU;
    uint32_t b3 = (n >> 24);
    uint32_t b1 = (n >> 8) & 0xFFU;
    uint32_t b2 = (n >> 16) & 0xFFU;

    m = (b0 << 24) | (b2 << 16) | (b1 << 8) | (b3);
    printf("%" PRIu32 "\n", m);


}

void task5() {
    uint32_t n, m;
    printf("Enter n: ");
    scanf_s("% SCNu32", &n);
    int number_of_ones = 0;
    int number_of_ones_max = 0;

    for (size_t i=0; i < sizeof(n); i++) {
        if ((1<<i)&n) {
            number_of_ones++;
        }
        else {
           if  (number_of_ones > number_of_ones_max);
        }
        number_of_ones_max = number_of_ones;
    }
    number_of_ones = 0;
}
