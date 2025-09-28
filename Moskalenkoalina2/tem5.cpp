#include <stdio.h>

double Rosenbrock2d(double x, double y) {
    return 100 * (x*x - y) * (x*x - y) + (x - 1) * (x - 1);
}

int main() {
    double x;
    double y;

    printf("Please enter the value of x: ");
    scanf("%lf", &x);
    printf("Please enter the value of y: ");
    scanf("%lf", &y);

    double res = Rosenbrock2d(x, y);
    printf("Rosenbrock2d = %2.f\n", res);
    return 0;

}