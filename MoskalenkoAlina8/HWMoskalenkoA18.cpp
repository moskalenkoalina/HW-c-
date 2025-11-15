#include <stdio.h>

#define MAX_N 100
#define MAX_M 100

int main() {
    int n, m;
    int matrix[MAX_N][MAX_M];

    printf("Enter the number of rows n: ");
    scanf("%d", &n);
    printf("Enter the number of columns m: ");
    scanf("%d", &m);

    if (n <= 0 || n > MAX_N || m <= 0 || m > MAX_M) {
        printf("Incorrect matrix dimensions!\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int first_row = -1;
    int last_row = -1;

    for (int i = 0; i < n; i++) {
        int all_negative = 1;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] >= 0) {
                all_negative = 0;
                break;
            }
        }
        if (all_negative) {
            if (first_row == -1) first_row = i;
            last_row = i;
        }
    }

    if (first_row != -1 && last_row != -1 && first_row != last_row) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[first_row][j];
            matrix[first_row][j] = matrix[last_row][j];
            matrix[last_row][j] = temp;
        }
    } else if (first_row == -1) {
        printf("No rows with only negative elements were found.\n");
    } else {
        printf("Only one row with negative elements found. Exchange not possible.\n");
    }

    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
