#include <stdio.h>

int main() {
    char a;
    printf("n =");
    scanf("%c", &a);

    printf("- %c - %c - %c \n", a, a, a );
    printf("%c | %c | %c \n", a, a, a );
    printf("- %c - %c - %c \n", a, a, a );

    return 0;
}