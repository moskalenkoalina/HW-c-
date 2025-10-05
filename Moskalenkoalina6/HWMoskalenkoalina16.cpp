#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon;
    

    printf("Enter x (|x| < 1): ");
    scanf("%lf", &x);
    printf("Ener e (> 0): ");
    scanf("%lf", &epsilon);
    

    if (fabs(x) >= 1) {
        printf("Error\n");
        return 1;
    }
    if (epsilon <= 0) {
        printf("Error\n");
        return 1;
    }
    
    double sum = 0.0;
    double term = 1.0;
    int n = 0;

    while (fabs(term) >= epsilon) {
        sum += term;
        n++;
        term = term * (-x * x);
    }

    printf("Sum: %.10f\n", sum);
    printf("Result: %.10f\n", 1.0 / (1.0 + x * x));
    printf("the number of terms: %d\n", n);
    printf("Measurement error: %.10f\n", fabs(sum - 1.0 / (1.0 + x * x)));
    
    return 0;
}