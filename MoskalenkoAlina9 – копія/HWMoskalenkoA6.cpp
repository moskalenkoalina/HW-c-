#include <stdio.h>
#include <stdlib.h>

double** create_matrix(int rows, int cols) {
    double **matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void input_matrix(double **matrix, int rows, int cols) {
    printf("Enter elements %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int k;
    int rows, cols;

    printf("Enter the number of matrices: ");
    scanf("%d", &k);

    printf("Enter the dimensions of the matrices: ");
    scanf("%d %d", &rows, &cols);

    double ***matrices = (double***)malloc(k * sizeof(double**));

    for (int i = 0; i < k; i++) {
        printf("\nMatrix %d:\n", i + 1);
        matrices[i] = create_matrix(rows, cols);
        input_matrix(matrices[i], rows, cols);
    }

    double **sum = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = 0;
            for (int m = 0; m < k; m++) {
                sum[i][j] += matrices[m][i][j];
            }
        }
    }

    printf("\nSuma:\n");
    print_matrix(sum, rows, cols);

    for (int i = 0; i < k; i++) {
        free_matrix(matrices[i], rows);
    }
    free(matrices);
    free_matrix(sum, rows);

    return 0;
}