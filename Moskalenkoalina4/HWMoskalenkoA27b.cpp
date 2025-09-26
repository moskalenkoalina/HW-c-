#include <stdio.h>

int main() {
    double epsilon;
    printf("Enter epsilon: ");
    scanf("%lf", &epsilon);

    double product = 1.0;
    double pi_approx = 2.0;
    double prev_pi;
    int n = 1;

    do {
        prev_pi = pi_approx;

        double num = 2.0 * n;
        double factor = (num / (num - 1)) * (num / (num + 1));
        product *= factor;
        pi_approx = 2.0 * product;

        n++;
    } while (pi_approx - prev_pi > epsilon || prev_pi - pi_approx > epsilon);

    printf("Approximation of pi: %.10f\n", pi_approx);

    return 0;
}