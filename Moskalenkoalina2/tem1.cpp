#include  <stdio.h>
#include <math.h>

int main() {
    double x;
    double res;

    printf("Enter value for x: ");
    scanf("%lf", &x);

    res = cos(x);
    printf("cos(%.2f) = %.2f\n", x, res);
    return 0;
}