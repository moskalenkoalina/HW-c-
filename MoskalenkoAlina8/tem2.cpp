#include <stdio.h>

int main() {
    double matrix[3][3] = {
        {1.0, 2.3, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    int i, j;
    double a;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%.1f\t", matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nEnetr i  (1-3): ");
    scanf("%d", &i);
    printf("Enter j (1-3): ");
    scanf("%d", &j);
    printf("Enter a: ");
    scanf("%lf", &a);

    if (i < 1 || i > 3 || j < 1 || j > 3) {
        printf("Error!\n");
        return 1;
    }

    matrix[i-1][j-1] = a;

    printf("\nResult:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%.1f\t", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}