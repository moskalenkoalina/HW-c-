#include <stdio.h>
#include <math.h>

int main() {
    double a,b;
    double c;

    printf("Enter a=");
    scanf("%lf", &a);
    printf("Enter b=");
    scanf("%lf", &b);

    c = sqrt(a*a + b*b);
    printf("c=%.2f\n", c);
    return 0;
}