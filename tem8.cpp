#include <stdio.h>

int main() {
    double num1, num2;
    
    printf("num1= ");
    scanf("%lf", &num1);
    
    printf("num2= ");
    scanf("%lf", &num2);
    
    double difference = num1 - num2;
    double product = num1 * num2;
    
    printf(" %.2f\n", difference);
    printf(" %.2f\n", product);
    
    return 0;
}