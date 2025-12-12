#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void inputDate(Date *d) {
    printf("Enter day, month, year: ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void outputDate(Date d) {
    printf("Date: %02d.%02d.%d\n", d.day, d.month, d.year);
}

typedef struct {
    char letter;
    int number;
} ChessSquare;

void inputChessSquare(ChessSquare *cs) {
    printf("Enter square (e.g., a5): ");
    scanf(" %c%d", &cs->letter, &cs->number);
}

void outputChessSquare(ChessSquare cs) {
    printf("Square: %c%d\n", cs.letter, cs.number);
}

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

void inputPoint(Point *p) {
    printf("Enter point coordinates (x y): ");
    scanf("%lf %lf", &p->x, &p->y);
}

void inputRectangle(Rectangle *rect) {
    printf("Enter top-left vertex:\n");
    inputPoint(&rect->topLeft);
    printf("Enter bottom-right vertex:\n");
    inputPoint(&rect->bottomRight);
}

void outputRectangle(Rectangle rect) {
    printf("Rectangle: (%.2f, %.2f) - (%.2f, %.2f)\n",
           rect.topLeft.x, rect.topLeft.y,
           rect.bottomRight.x, rect.bottomRight.y);
}

typedef struct {
    int degree;
    double *coefficients;
} Polynomial;

void inputPolynomial(Polynomial *poly) {
    printf("Enter polynomial degree: ");
    scanf("%d", &poly->degree);
    
    poly->coefficients = (double*)malloc((poly->degree + 1) * sizeof(double));
    
    printf("Enter coefficients from a0 to a%d:\n", poly->degree);
    for (int i = 0; i <= poly->degree; i++) {
        scanf("%lf", &poly->coefficients[i]);
    }
}

void outputPolynomial(Polynomial poly) {
    printf("Polynomial: ");
    for (int i = 0; i <= poly.degree; i++) {
        printf("%+.2lf", poly.coefficients[i]);
        if (i > 0) printf("x^%d", i);
    }
    printf("\n");
}

void freePolynomial(Polynomial *poly) {
    free(poly->coefficients);
}

int main() {
    Date d;
    inputDate(&d);
    outputDate(d);

    ChessSquare cs;
    inputChessSquare(&cs);
    outputChessSquare(cs);

    Rectangle rect;
    inputRectangle(&rect);
    outputRectangle(rect);

    Polynomial poly;
    inputPolynomial(&poly);
    outputPolynomial(poly);
    freePolynomial(&poly);

    return 0;
}