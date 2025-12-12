
#include "geometry.h"

int main() {
    // Тест Point
    Point p;
    std::cout << "Enter point:\n";
    p.input();
    std::cout << "Point: ";
    p.output();
    std::cout << "\n\n";

    // Тест Segment
    Segment s;
    std::cout << "Enter segment:\n";
    s.input();
    std::cout << "Segment: ";
    s.output();
    std::cout << "\n";

    Point mid = s.midpoint();
    std::cout << "Midpoint: ";
    mid.output();
    std::cout << "\n";

    std::cout << "Length: " << s.length() << "\n\n";

    // Тест перетину відрізків
    Segment s1, s2;
    std::cout << "Segment 1 for intersection:\n";
    s1.input();
    std::cout << "Segment 2 for intersection:\n";
    s2.input();

    Point inter = Segment::intersection(s1, s2);
    std::cout << "Intersection: ";
    inter.output();
    std::cout << "\n\n";

    // Тест Triangle
    Triangle t;
    std::cout << "Enter triangle:\n";
    t.input();
    std::cout << "Triangle: ";
    t.output();
    std::cout << "\n";

    std::cout << "Perimeter: " << t.perimeter() << "\n";
    std::cout << "Area: " << t.area() << "\n";

    return 0;
}