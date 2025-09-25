#include <stdio.h>

int main() {
    double x;
    printf("x= ");
    scanf("%lf", &x);

    int integer_part = (int)x;

    double fractional_part = x - integer_part;

    int ceil_value;
    if (x == (double)integer_part) {
        ceil_value = integer_part;
    } else if (x > 0) {
        ceil_value = integer_part + 1;
    } else {
        ceil_value = integer_part;
    }

    int floor_value;
    if (x == (double)integer_part) {
        floor_value = integer_part;
    } else if (x > 0) {
        floor_value = integer_part;
    } else {
        floor_value = integer_part - 1;
    }

    int rounded_value;
    if (x >= 0) {
        rounded_value = (int)(x + 0.5);
    } else {
        rounded_value = (int)(x - 0.5);
    }

    printf(" %d\n", integer_part);
    printf(" %f\n", fractional_part);
    printf(" %d\n", ceil_value);
    printf(" %d\n", floor_value);
    printf(" %d\n", rounded_value);
    
    return 0;
}