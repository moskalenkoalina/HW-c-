#include <stdio.h>
#include <math.h>

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}

double calculateS(double a, double b, double c ) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));

}

int main() {
    double xA, yA, xB, yB, xC, yC;
    printf("A(x,y)=");
    scanf("%lf %lf", &xA, &yA);

    getchar();

    printf("ENTER");
    getchar();

    printf("B(x,y)=");
    scanf("%lf %lf", &xB, &yB);

    getchar();

    printf("ENTER");
    getchar();

    printf("C(x,y)=");
    scanf("%lf %lf", &xC, &yC);


    double AB = calculateDistance(xA, yA, xB, yB);
    double AC = calculateDistance(xA, yA, xC, yC);
    double BC = calculateDistance(xB, yB, xC, yC);
    double area = calculateS(AB, AC, BC);
    printf("AREA=%.2f\n", area);
    return 0;



}