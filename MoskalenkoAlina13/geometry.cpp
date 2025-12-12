
#include "geometry.h"
#include <cmath>

// Point
Point::Point() : x(0), y(0), empty(true) {}
Point::Point(double x, double y) : x(x), y(y), empty(false) {}

void Point::input() {
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    empty = false;
}

void Point::output() const {
    if (empty) {
        std::cout << "(empty)";
    } else {
        std::cout << "(" << x << "," << y << ")";
    }
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
bool Point::isEmpty() const { return empty; }

void Point::setX(double x) { this->x = x; empty = false; }
void Point::setY(double y) { this->y = y; empty = false; }
void Point::setEmpty() { empty = true; }

// Segment
Segment::Segment() {}
Segment::Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

void Segment::input() {
    std::cout << "Point 1:\n";
    p1.input();
    std::cout << "Point 2:\n";
    p2.input();
}

void Segment::output() const {
    p1.output();
    std::cout << " - ";
    p2.output();
}

Point Segment::midpoint() const {
    double mx = (p1.getX() + p2.getX()) / 2;
    double my = (p1.getY() + p2.getY()) / 2;
    return Point(mx, my);
}

double Segment::length() const {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return sqrt(dx*dx + dy*dy);
}

Point Segment::intersection(const Segment& s1, const Segment& s2) {
    double x1 = s1.p1.getX(), y1 = s1.p1.getY();
    double x2 = s1.p2.getX(), y2 = s1.p2.getY();
    double x3 = s2.p1.getX(), y3 = s2.p1.getY();
    double x4 = s2.p2.getX(), y4 = s2.p2.getY();

    double den = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);

    if (fabs(den) < 0.0001) {
        return Point();
    }

    double t = ((x1 - x3)*(y3 - y4) - (y1 - y3)*(x3 - x4)) / den;
    double u = -((x1 - x2)*(y1 - y3) - (y1 - y2)*(x1 - x3)) / den;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        double ix = x1 + t*(x2 - x1);
        double iy = y1 + t*(y2 - y1);
        return Point(ix, iy);
    }

    return Point();
}

// Triangle
Triangle::Triangle() {}
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : p1(p1), p2(p2), p3(p3) {}

void Triangle::input() {
    std::cout << "Vertex 1:\n";
    p1.input();
    std::cout << "Vertex 2:\n";
    p2.input();
    std::cout << "Vertex 3:\n";
    p3.input();
}

void Triangle::output() const {
    p1.output();
    std::cout << ", ";
    p2.output();
    std::cout << ", ";
    p3.output();
}

double Triangle::perimeter() const {
    double a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    double b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
    double c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
    return a + b + c;
}

double Triangle::area() const {
    double a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    double b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
    double c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}