#include <stdio.h>
#include <math.h>

double eReLu(double a, double x) {
    if (x < 0) {
        return a * (exp(x) - 1);
    } else {
        return 0.0;
    }
}

double eReLu_derivative(double a, double x) {
    if (x < 0) {
        return a * exp(x);
    } else {
        return 0.0;
    }
}

int main() {
    double a, x;
    
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter x: ");
    scanf("%lf", &x);
    
    double result = eReLu(a, x);
    double derivative = eReLu_derivative(a, x);
    
    printf("eReLu(%.2f, %.2f) = %.6f\n", a, x, result);
    printf("derivative eReLu(%.2f, %.2f) = %.6f\n", a, x, derivative);



    
    for (double test_x = -2.0; test_x <= 2.0; test_x += 0.5) {
        double func_val = eReLu(a, test_x);
        double deriv_val = eReLu_derivative(a, test_x);
        printf("%.1f\t\t%.6f\t\t%.6f\n", test_x, func_val, deriv_val);
    }
    
    return 0;
}