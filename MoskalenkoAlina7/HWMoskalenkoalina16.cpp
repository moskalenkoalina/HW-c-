#include <stdio.h>

double calculate_function(double x[], int d) {
    double sum = 0.0;

    for (int i = 0; i < d; i++) {
        double term1;
        if (i < d - 1) {
            term1 = 100.0 * x[i + 1] - x[i];
        } else {
            term1 = -x[i];
        }

        double term2 = x[i] - 1.0;

        sum += term1 * term1 + term2 * term2;
    }

    return sum;
}

double calculate_function_alternative(double x[], int d) {
    if (d < 2) {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < d - 1; i++) {
        double term1 = 100.0 * x[i + 1] - x[i];
        double term2 = x[i] - 1.0;

        sum += term1 * term1 + term2 * term2;
    }

    return sum;
}

int main() {
    double x1[] = {1.0, 2.0, 3.0};
    int d1 = 3;

    printf("Result1: %.6f\n", calculate_function(x1, d1));
    printf("Result2: %.6f\n\n", calculate_function_alternative(x1, d1));

    double x2[] = {0.5, 1.5, 2.5, 3.5};
    int d2 = 4;

    printf("Result1: %.6f\n", calculate_function(x2, d2));
    printf("Resulr2: %.6f\n\n", calculate_function_alternative(x2, d2));

    double x3[] = {2.0};
    int d3 = 1;

    printf("Result1: %.6f\n", calculate_function(x3, d3));
    printf("Result2: %.6f\n\n", calculate_function_alternative(x3, d3));

    return 0;
}