#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    printf("Enter numbers (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double abs_a = fabs(a);
    double abs_b = fabs(b);
    double abs_c = fabs(c);

    double max_abs_num;
    if (abs_a >= abs_b && abs_a >= abs_c) {
        max_abs_num = a;
    } else if (abs_b >= abs_a && abs_b >= abs_c) {
        max_abs_num = b;
    } else {
        max_abs_num = c;
    }

    double min_abs_num;
    if (abs_a <= abs_b && abs_a <= abs_c) {
        min_abs_num = a;
    } else if (abs_b <= abs_a && abs_b <= abs_c) {
        min_abs_num = b;
    } else {
        min_abs_num = c;
    }
    printf("The number with the largest modulus: %f\n",
           max_abs_num, max_abs_num, fabs(max_abs_num));
    printf("The number with the small modulus: %f\n",
           min_abs_num, min_abs_num, fabs(min_abs_num));

    return 0;
}