#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double p;
    double s;

    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the value of c: ");
    scanf("%lf", &c);

    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("S =  %2.f\n", s);
    return 0;
}