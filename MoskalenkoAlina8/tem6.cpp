#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int N, M, k;
    double A[MAX_SIZE][MAX_SIZE];
    double sum = 0.0;

    printf("Enter N (N < 100): ");
    scanf("%d", &N);
    printf(" Enter M (M < 100): ");
    scanf("%d", &M);

    if (N <= 0 || M <= 0 || N >= MAX_SIZE || M >= MAX_SIZE) {
        printf("No correct!\n");
        return 1;
    }

    printf("Enter elements of matrix %dx%d:\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter real number k: ");
    scanf("%d", &k);

    for (int i = 0; i < N; i++) {
        int j = i - k;
        if (j >= 0 && j < M) {
            sum += A[i][j];
        }
    }

    printf("Suma elemets , i - j = %d: %.2f\n", k, sum);

    return 0;
}