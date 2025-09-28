#include <stdio.h>
#include <math.h>

double softSign(double x) {
    return x / (1.0 + fabs(x));
}


double softSign_derivative(double x) {
    double temp = 1.0 + fabs(x);
    return 1.0 / (temp * temp);
}

int main() {
    double x;
    
    printf("Enter x: ");
    scanf("%lf", &x);
    
    printf("softSign(%.2f) = %.4f\n", x, softSign(x));
    printf("Derivative = %.4f\n", softSign_derivative(x));
    
    return 0;
}