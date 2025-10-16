#include <stdio.h>
#include <math.h>

#define N 10

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


double sum_greater_than_euler(double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > M_E) {
            sum += arr[i];
        }
    }
    return sum;
}

void task1() {
    double array[N];
    
    printf("Enter %d real numbers:\n", N);
    

    for (int i = 0; i < N; i++) {
        printf("Element [%d]: ", i);
        scanf("%lf", &array[i]);
    }

    printf("\nEntered array: ");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    

    double result = sum_greater_than_euler(array, N);
    
    printf("Euler's number (e) = %.5f\n", M_E);
    printf("Sum of elements greater than e: %.2f\n", result);
}