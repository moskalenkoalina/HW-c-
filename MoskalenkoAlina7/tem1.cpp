#include <stdio.h>
#define N 5

void task1();

int main() {
    int task_number = 1;
    switch (task_number) {
        case 1:
            task1();
            break;
        default:
            printf("task1 is not a valid task number\n");
    }

}

void task1() {
    int a[] = {1, 2, 3, 4, 5};
    int k = 0;
    double x;

    printf("x=");
    scanf("%lf", &x);

    for (int i = 0; i < N; i++) {
        if (a[i] < x) {
            k++;
        }
    }
    printf("k=%d\n", k);
}