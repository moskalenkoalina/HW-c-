#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int numVertices;
    Point *vertices;
} Polygon;

void inputPolygon(Polygon *poly) {
    printf("How many vertices does the polygon have? ");
    scanf("%d", &poly->numVertices);

    if (poly->numVertices < 3) {
        printf("Error: at least 3 vertices required!\n");
        exit(1);
    }

    poly->vertices = (Point*)malloc(poly->numVertices * sizeof(Point));

    for (int i = 0; i < poly->numVertices; i++) {
        printf("Enter coordinates of vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &poly->vertices[i].x, &poly->vertices[i].y);
    }
}

void outputPolygon(Polygon poly) {
    printf("\nThe polygon has %d vertices:\n", poly.numVertices);
    for (int i = 0; i < poly.numVertices; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly.vertices[i].x, poly.vertices[i].y);
    }
}

double calculatePerimeter(Polygon poly) {
    double perimeter = 0.0;
    double dx, dy;

    for (int i = 0; i < poly.numVertices; i++) {
        int j = (i + 1) % poly.numVertices;
        dx = poly.vertices[j].x - poly.vertices[i].x;
        dy = poly.vertices[j].y - poly.vertices[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }

    return perimeter;
}

int main() {
    Polygon myPolygon;
    double perimeter;

    printf("=== Polygon Perimeter Calculation ===\n");

    inputPolygon(&myPolygon);
    outputPolygon(myPolygon);

    perimeter = calculatePerimeter(myPolygon);
    printf("\nPolygon perimeter: %.2f\n", perimeter);

    free(myPolygon.vertices);

    printf("\nProgram finished!\n");
    return 0;
}
