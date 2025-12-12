#include <stdio.h>
#include <stdlib.h>

double* create_vector(int n) {
    double* vector = (double*)malloc(n * sizeof(double));

    printf("Enter %d vector elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &vector[i]);
    }

    return vector;
}

void free_vector(double* vector) {
    free(vector);
}

double* vector_difference(const double* vec1, const double* vec2, int n) {
    double* result = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i] = vec1[i] - vec2[i];
    }

    return result;
}

void print_vector(const double* vector, int n, const char* name) {
    printf("%s = [", name);
    for (int i = 0; i < n; i++) {
        printf("%.2f", vector[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;

    printf("Enter vector dimension: ");
    scanf("%d", &n);

    printf("\n First vector \n");
    double* vector1 = create_vector(n);

    printf("\nSecond vector \n");
    double* vector2 = create_vector(n);

    printf("\n Input vectors\n");
    print_vector(vector1, n, "Vector 1");
    print_vector(vector2, n, "Vector 2");

    double* difference = vector_difference(vector1, vector2, n);

    printf("\nVector difference\n");
    print_vector(difference, n, "Difference");

    free_vector(vector1);
    free_vector(vector2);
    free_vector(difference);

    return 0;
}