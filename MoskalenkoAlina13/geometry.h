
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

class Point {
private:
    double x, y;
    bool empty;

public:
    Point();
    Point(double x, double y);
    void input();
    void output() const;
    double getX() const;
    double getY() const;
    bool isEmpty() const;
    void setX(double x);
    void setY(double y);
    void setEmpty();
};

class Segment {
private:
    Point p1, p2;

public:
    Segment();
    Segment(const Point& p1, const Point& p2);
    void input();
    void output() const;
    Point midpoint() const;
    double length() const;
    static Point intersection(const Segment& s1, const Segment& s2);
};

class Triangle {
private:
    Point p1, p2, p3;

public:
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    void input();
    void output() const;
    double perimeter() const;
    double area() const;
};

#endif