#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

Point inputPoint() {
    Point point = {};
    cout << "Enter point coordinates: ";
    cin >> point.x >> point.y;
    return point;
}

vector<Point> inputPolygon() {
    int n;
    cout << "Enter number of polygon's vertices ";
    cin >> n;
    vector<Point> polygon(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter " << (i + 1) << " point coordinates: ";
        cin >> polygon.at(i).x >> polygon.at(i).y;
    }
    return polygon;
}

double countPolygonArea(vector<Point> &polygon) {
    double S = 0.0;
    int n = polygon.size();
    for(int i = 0; i < (n - 1); i++) {
        S += polygon.at(i).x * polygon.at(i+1).y;
        S -= polygon.at(i+1).x * polygon.at(i).y;
    }
    S += polygon.at(n-1).x * polygon.at(0).y;
    S -= polygon.at(0).x * polygon.at(n-1).y;
    S = abs(S)/2.0;
    return S;
}

double countTrianglesArea(vector<Point> &polygon, Point &point) {
    double S = 0.0;
    int n = polygon.size();
    for(int i = 0; i < (n - 1); i++) {
        vector<Point> triangle = {polygon.at(i), polygon.at(i+1), point};
        S += countPolygonArea(triangle);
    }
    vector<Point> triangle = {polygon.at(0), polygon.at(n-1), point};
    S += countPolygonArea(triangle);
    return S;
}

bool check(double S1, double S2) {
    if(abs(S1 - S2) < 1e-5) return true;
    else return false;
}

void output(bool res) {
    if(res) cout << "Point is inside the polygon.\n";
    else cout << "Point is outside the polygon.\n";
}

int main() {
    Point point = inputPoint();
    vector<Point> polygon = inputPolygon();
    double S1 = countPolygonArea(polygon);
    double S2 = countTrianglesArea(polygon, point);
    bool res = check(S1, S2);
    output(res);
    return 0;
}