#include <stdio.h>
#include <stdlib.h>

double* create_vector(int n) {
    double *vector = (double*)malloc(n * sizeof(double));
    printf("Enter %d vector elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vector[i]);
    }
    return vector;
}

void free_vector(double *vector) {
    free(vector);
}

int main() {
    int n;
    double *v1, *v2, *result;

    printf("Enter the dimension of the vectors: ");
    scanf("%d", &n);

    printf("First vector:\n");
    v1 = create_vector(n);

    printf("Second vector:\n");
    v2 = create_vector(n);

    result = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] - v2[i];
    }
    printf("Difference of vectors: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", result[i]);
    }
    printf("\n");

    free_vector(v1);
    free_vector(v2);
    free_vector(result);

    return 0;
}