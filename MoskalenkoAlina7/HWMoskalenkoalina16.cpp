#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

double calculate_function(double x[], int d) {
    double sum = 0.0;

    for (int i = 0; i < d; i++) {
        double xi = x[i];
        double xi1 = x[(i + 1) % d]; // x[d] → x[0]

        double term1 = 100.0 * xi1 - xi;
        double term2 = xi - 1.0;

        sum += term1 * term1 + term2 * term2;
    }

    return sum;
}

void input_array(double arr[], int n) {
    printf("enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void print_array(double arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.4f", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

void analyze_array(double arr[], int n) {
    if (n <= 0) return;

    double max = arr[0];
    double min = arr[0];
    double sum = 0.0;
    double sum_squares = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        sum += arr[i];
        sum_squares += arr[i] * arr[i];
    }

    double mean = sum / n;
    double variance = (sum_squares / n) - (mean * mean);
    double std_dev = sqrt(variance);

    printf("Dimensionality: %d\n", n);
    printf("Max: %.4f\n", max);
    printf("Min: %.4f\n", min);
    printf("Average value: %.4f\n", mean);
    printf("Dispersion: %.4f\n", variance);
    printf("deviation: %.4f\n", std_dev);
    printf("Suma elements: %.4f\n", sum);
}

int main() {
    int d;
    double x[MAX_SIZE];

    printf("Enter Dimensionality d (< 100): ");
    scanf("%d", &d);

    input_array(x, d);

    printf("\n array: ");
    print_array(x, d);

    double result = calculate_function(x, d);

    printf("\n\nThe value of the function f(x) = %.6f\n", result);

    analyze_array(x, d);

    return 0;
}


