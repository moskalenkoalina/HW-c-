#include <stdio.h>

int main() {
    double m1, m2, r;
    const double y = 6.673e-11;

    printf("m1=");
    scanf("%lf", &m1);
    printf("m2=");
    scanf("%lf", &m2);
    printf("r=");
    scanf("%lf", &r);

    double F = y*(m1*m2)/(r*r);
    printf("F=%.e\n", F);
    return 0;

}