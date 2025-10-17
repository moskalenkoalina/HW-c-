#include <stdio.h>
#define N 25
#define M 25

void inputMatrix(int arr[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("Enter row %d: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void outputMatrix(int arr[N][M], int n, int m) {
    printf("\nMatrix %dx%d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int matrix[N][M];

    printf("Enter number of rows (n < 25): ");
    scanf("%d", &n);
    printf("Enter number of columns (m < 25): ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0 || n > N || m > M) {
        printf("Error: Invalid matrix dimensions!\n");
        return 1;
    }

    inputMatrix(matrix, n, m);
    outputMatrix(matrix, n, m);

    return 0;
}