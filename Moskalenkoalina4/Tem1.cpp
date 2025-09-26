#include <stdio.h>
#include <math.h>
int main() {
    double x=0, y=0;
    unsigned n;
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%u", &n);
    y=x;
    for (unsigned i=0; i<n; i++) {y=sin(y);}
    printf("y=%lf\n", y);
}