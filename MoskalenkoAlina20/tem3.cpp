#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
    double length;
};

double countLength(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool sortByLength(Segment a, Segment b) {
    return a.length < b.length;
}

int main() {
    ifstream input("points.txt");
    if (!input) {
        cout << "Error! Cannot open file points.txt" << endl;
        return 1;
    }

    vector<Point> points;
    char ch;
    int x, y;
    
    while (input >> ch) {
        input >> x;
        input >> ch;
        input >> y;
        input >> ch;
        points.push_back({x, y});
        if (input.peek() == ' ') {
            input.get();
        }
    }
    
    input.close();
    
    cout << "Read " << points.size() << " points:" << endl;
    for (int i = 0; i < points.size(); i++) {
        cout << "(" << points[i].x << "," << points[i].y << ") ";
    }
    cout << endl << endl;
    
    vector<Segment> segments;
    
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double len = countLength(points[i], points[j]);
            segments.push_back({points[i], points[j], len});
        }
    }
    
    cout << "Created " << segments.size() << " segments" << endl;
    
    sort(segments.begin(), segments.end(), sortByLength);
    
    ofstream output("segments.txt");
    if (!output) {
        cout << "Error! Cannot create file segments.txt" << endl;
        return 1;
    }
    
    output << "Segments sorted by length (ascending):" << endl;
    
    for (int i = 0; i < segments.size(); i++) {
        output << "(" << segments[i].p1.x << "," << segments[i].p1.y << ")-("
               << segments[i].p2.x << "," << segments[i].p2.y << ")  ";
        output << "length: " << fixed << setprecision(3) << segments[i].length << endl;
    }
    
    output.close();
    
    cout << endl << "First 5 shortest segments:" << endl;
    
    for (int i = 0; i < min(5, (int)segments.size()); i++) {
        cout << "(" << segments[i].p1.x << "," << segments[i].p1.y << ")-("
             << segments[i].p2.x << "," << segments[i].p2.y << ")  ";
        cout << "length: " << fixed << setprecision(3) << segments[i].length << endl;
    }
    
    if (segments.size() > 0) {
        cout << endl << "Longest segment:" << endl;
        cout << "(" << segments.back().p1.x << "," << segments.back().p1.y << ")-("
             << segments.back().p2.x << "," << segments.back().p2.y << ")  ";
        cout << "length: " << fixed << setprecision(3) << segments.back().length << endl;
    }
    
    cout << endl << "File segments.txt successfully created!" << endl;
    
    return 0;
}
