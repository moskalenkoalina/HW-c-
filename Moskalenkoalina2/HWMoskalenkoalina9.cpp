#include <stdio.h>
#include <math.h>

#define PI 3.14

int main() {
    double angle1, angle2, angle3, r;

    printf("Angle 1: ");
    scanf("%lf", &angle1);
    printf("Angle 2: ");
    scanf("%lf", &angle2);
    printf("Angle 3: ");
    scanf("%lf", &angle3);

    printf("Enter the r: ");
    scanf("%lf", &r);

    double sum_angles = angle1 + angle2 + angle3;
    if (sum_angles < 179.9999 || sum_angles > 180.0001) {
        printf("Error: The sum of triangle angles must equal 180 degrees!\n");
        return 1;
    }

    double a1_rad = angle1 * PI / 180.0;
    double a2_rad = angle2 * PI / 180.0;
    double a3_rad = angle3 * PI / 180.0;

    double ctg1 = cos(a1_rad / 2) / sin(a1_rad / 2);
    double ctg2 = cos(a2_rad / 2) / sin(a2_rad / 2);
    double ctg3 = cos(a3_rad / 2) / sin(a3_rad / 2);

    double area = r * r * (ctg1 + ctg2 + ctg3);

    printf("\nArea of the triangle: %.2f\n", area);

    return 0;
}