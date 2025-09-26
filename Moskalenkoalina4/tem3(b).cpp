#include <stdio.h>
#include <math.h>
int main() {
    double x=0, y=0,t=0;
    unsigned n;
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%u", &n);
    t=1;
    y=1;
    for (unsigned i=1; i<n; i++) {t*=x;y+=t;}
    printf("y=%lf\n", y);
}