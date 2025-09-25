#include <stdio.h>

int main() {
    double v, m,E;
    printf("v= ");
    scanf("%lf", &v);
    printf("m= ");
    scanf("%lf", &m);

    E = m * (v*v) / 2;
    printf("E= %lf\n", E);
    return 0;

}