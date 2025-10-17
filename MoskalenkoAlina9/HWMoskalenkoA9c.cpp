#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m;

    printf("Enter line matrix N: ");
    scanf("%d", &n);
    printf("Enter columns matrix M: ");
    scanf("%d", &m);

    double **matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
    }

    printf("Enter element matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("\nOriginal matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    double min_abs = fabs(matrix[0][0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double current_abs = fabs(matrix[i][j]);
            if (current_abs < min_abs) {
                min_abs = current_abs;
            }
        }
    }
    printf("\nThe smallest element by modulus: %.2lf\n", min_abs);

    int *delete_row = (int*)calloc(n, sizeof(int));
    int delete_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fabs(matrix[i][j]) == min_abs) {
                delete_row[i] = 1;
                delete_count++;
                break;
            }
        }
    }

    int new_n = n - delete_count;
    if (new_n > 0) {
        double **new_matrix = (double**)malloc(new_n * sizeof(double*));
        for (int i = 0; i < new_n; i++) {
            new_matrix[i] = (double*)malloc(m * sizeof(double));
        }

        int new_i = 0;
        for (int i = 0; i < n; i++) {
            if (!delete_row[i]) {
                for (int j = 0; j < m; j++) {
                    new_matrix[new_i][j] = matrix[i][j];
                }
                new_i++;
            }
        }

        printf("\nMatrix after removing rows:\n");
        for (int i = 0; i < new_n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%.2lf\t", new_matrix[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < new_n; i++) {
            free(new_matrix[i]);
        }
        free(new_matrix);
    } else {
        printf("\nAll lines have been deleted!\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(delete_row);

    return 0;
}