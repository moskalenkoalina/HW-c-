#include <stdio.h>
#include <math.h>
double exp_tail(double x, unsigned n) {
    double y = 1, t = 1;
    for (unsigned i = 1; i <= n; i++) {
        (t *= x/i);
        y += t;
    }
    return y;
}
int main() {
    double x=; unsigned n;
    printf("x=");
    scanf("%lf", &x);
}
while (fabs(x));
scanf()
