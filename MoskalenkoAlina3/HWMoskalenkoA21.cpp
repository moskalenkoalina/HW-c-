#include <stdio.h>
#include <math.h>

int main() {
    double x, y, z, R;

    printf("Enter(x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    printf("Enter R: ");
    scanf("%lf", &R);

    double distance = sqrt(x*x + y*y + z*z);

    if (distance <= R) {
        printf("(%.2f, %.2f, %.2f) It is a ball with a radius R=%.2f\n",
               x, y, z, R);
        printf("Distance to the center: %.2f <= %.2f\n", distance, R);
    } else {
        printf(" (%.2f, %.2f, %.2f) does not belong to a sphere with radius R=%.2f\n",
               x, y, z, R);
        printf("Distance to the center: %.2f > %.2f\n", distance, R);
    }
    
    return 0;
}