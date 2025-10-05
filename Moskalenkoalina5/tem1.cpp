#include <stdio.h>

void task1();

int main() {
    int task_index=1;
    if (task_index==1) {
        task1();
    }
}
void task1() {
    unsigned char n;
    printf("Enter a number: ");
    scanf_s("%hh", &n);
    if (n < 64) {
        unsigned long long m = 1UL<<n;
        printf("%Lx\n", m);
    }

}