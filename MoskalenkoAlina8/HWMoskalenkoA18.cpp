#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);

    int **matrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        printf("Line %d: ", i + 1);
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int first_non_neg = -1;
    int last_non_neg = -1;

    for(int i = 0; i < n; i++) {
        int all_non_negative = 1;

        for(int j = 0; j < m; j++) {
            if(matrix[i][j] < 0) {
                all_non_negative = 0;
                break;
            }
        }

        if(all_non_negative) {
            if(first_non_neg == -1) {
                first_non_neg = i;
            }
            last_non_neg = i;
        }
    }

    printf("\nOrigin matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if(first_non_neg != -1 && last_non_neg != -1 && first_non_neg != last_non_neg) {
        printf("Swapping rows %d and %d\n", first_non_neg + 1, last_non_neg + 1);

        int *temp = matrix[first_non_neg];
        matrix[first_non_neg] = matrix[last_non_neg];
        matrix[last_non_neg] = temp;

        printf("Result:\n");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
    } else if(first_non_neg == -1) {
        printf("\nError. No rows with all non-negative elements.\n");
    } else {
        printf("\nError. First and last non-negative rows are the same.\n");
    }

    for(int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}