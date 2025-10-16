#include <stdio.h>
#define MAX_SIZE 20

void inputVector(double vector[], int *n) {
    printf("Enter vector n = ");
    scanf("%d", n);

    while (*n <= 0 || *n >= MAX_SIZE) {
        printf("Not correct n. Enter again: ");
        scanf("%d", n);
    }

    printf("Enter %d real numbers:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Element [%d]: ", i);
        scanf("%lf", &vector[i]);
    }
}

void printVector(double vector[], int n) {
    printf("Vector: [");
    for (int i = 0; i < n; i++) {
        printf("%.2f", vector[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void addVectors(double vector1[], double vector2[], double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = vector1[i] + vector2[i];
    }
}


double dotProduct(double vector1[], double vector2[], int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += vector1[i] * vector2[i];
    }
    return result;
}

int main() {
    double vector1[MAX_SIZE], vector2[MAX_SIZE], result[MAX_SIZE];
    int n1, n2;


    printf("=== First vector ===\n");
    inputVector(vector1, &n1);
    printVector(vector1, n1);


    printf("\n=== Second vector ===\n");
    inputVector(vector2, &n2);
    printVector(vector2, n2);


    if (n1 != n2) {
        printf("\nError: Vectors have different dimensions (%d != %d)\n", n1, n2);
        printf("Vector operations are not possible!\n");
        return 1;
    }


    addVectors(vector1, vector2, result, n1);


    double scalar = dotProduct(vector1, vector2, n1);


    printf("\n=== Results ===\n");
    printf("Vector 1: ");
    printVector(vector1, n1);
    printf("Vector 2: ");
    printVector(vector2, n1);
    printf("Sum of vectors: ");
    printVector(result, n1);
    printf("Dot product of vectors: %.2f\n", scalar);

    return 0;
}