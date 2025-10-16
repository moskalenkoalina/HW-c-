#include <stdio.h>
#define N 4

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
    return 0;
}

void task1() {
    int a[] = {5, 112, 4, 3};
    
    printf("Array elements in reverse order: ");
    

    for (int i = N - 1; i >= 0; i--) {
        printf("%d", a[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("\n");
}