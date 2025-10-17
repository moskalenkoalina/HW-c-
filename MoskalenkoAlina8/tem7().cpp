#include <stdio.h>
#define N 255
#define M 255

double determinant(double a[N][M], int n) {
    double det = 1.0;
    double temp;

    double mat[N][M];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            int found = 0;
            for (int k = i + 1; k < n; k++) {
                if (mat[k][i] != 0) {
                    for (int j = 0; j < n; j++) {
                        temp = mat[i][j];
                        mat[i][j] = mat[k][j];
                        mat[k][j] = temp;
                    }
                    det *= -1;
                    found = 1;
                    break;
                }
            }
            if (!found) return 0;
        }

        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j < n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
        
        det *= mat[i][i];
    }
    
    return det;
}

int main() {
    int n;
    double matrix[N][M];
    
    printf("Sixe matrix: ");
    scanf("%d", &n);
    
    printf("Enter matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    
    double det = determinant(matrix, n);
    printf("determinant: %.2f\n", det);
    
    return 0;
}