#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
private:
    double x, y;
    static int count;

public:
    Point() {
        x = 0;
        y = 0;
        count++;
    }

    Point(double a, double b) {
        x = a;
        y = b;
        count++;
    }

    ~Point() {
        count--;
    }

    static int getCount() {
        return count;
    }

    double getX() { return x; }
    double getY() { return y; }

    void setX(double a) { x = a; }
    void setY(double b) { y = b; }

    double dist(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    void print() {
        cout << "(" << x << "," << y << ")";
    }
};

int Point::count = 0;

int main() {
    vector<Point> poly;
    char ans;
    
    cout << "Polygon input\n";
    
    do {
        double xx, yy;
        cout << "\nEnter x: ";
        cin >> xx;
        cout << "Enter y: ";
        cin >> yy;
        
        Point p(xx, yy);
        poly.push_back(p);
        
        cout << "Add another point? (y/n): ";
        cin >> ans;
    } while(ans == 'y' || ans == 'Y');
    
    cout << "\nNumber of vertices: " << Point::getCount() << endl;
    
    double per = 0;
    if(poly.size() > 1) {
        for(int i = 0; i < poly.size(); i++) {
            int j = (i + 1) % poly.size();
            per += poly[i].dist(poly[j]);
        }
    }
    
    cout << "Perimeter: " << per << endl;
    
    cout << "\nPolygon vertices:\n";
    for(int i = 0; i < poly.size(); i++) {
        cout << i+1 << ". ";
        poly[i].print();
        cout << endl;
    }
    
    return 0;
}
