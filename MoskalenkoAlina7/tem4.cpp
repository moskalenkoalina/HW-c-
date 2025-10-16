#include <stdio.h>
#define SIZE 5


void inputArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}


int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int array[SIZE];
    

    inputArray(array, SIZE);
    

    printf("\nEntered array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    

    int max_value = findMax(array, SIZE);
    printf("Maximum value in the array: %d\n", max_value);
    
    return 0;
}