#include <stdio.h>

static const int N = 20;
static const int M = 20;

void InputMatrix(double matrix[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void OutputMatrix(double matrix[N][M], int n, int m) {
    printf("Matrix %dx%d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    double matrix[N][M];

    printf("Enter n (n < %d): ", N);
    scanf("%d", &n);
    printf("Enter m (m < %d): ", M);
    scanf("%d", &m);

    if (n <= 0 || n >= N || m <= 0 || m >= M) {
        printf("Error %d\n", N-1);
        return 1;
    }

    InputMatrix(matrix, n, m);
    OutputMatrix(matrix, n, m);

    return 0;
}