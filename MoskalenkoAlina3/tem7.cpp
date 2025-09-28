#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    
    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);


    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("The equation has infinitely many solutions (identity)\n");
            } else {
                printf("The equation has no solutions\n");
            }
        } else {
            double x = -c / b;
            printf("The equation is linear, it has one solution:\n");
            printf("x = %.2f\n", x);
        }
    } else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("The equation has two real solutions:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        } else if (discriminant == 0) {
            double x = -b / (2 * a);
            printf("The equation has one solution (a double root):\n");
            printf("x = %.2f\n", x);
        } else {
            printf("The equation has no real solutions\n");

            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            printf("Complex roots:\n");
            printf("x1 = %.2f + %.2fi\n", realPart, imaginaryPart);
            printf("x2 = %.2f - %.2fi\n", realPart, imaginaryPart);
        }
    }

    return 0;
}
