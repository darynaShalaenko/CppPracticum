#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double countLength(Point* A, Point* B) {
    double x2 = pow((A->x - B->x), 2);
    double y2 = pow((A->y - B->y) , 2);
    return sqrt(x2 + y2);
}

struct Triangle {
    Point A, B, C;
};

double countArea(Triangle* t) {
    double a = countLength(&(t->A), &(t->B));
    double b = countLength(&(t->B), &(t->C));
    double c = countLength(&(t->A), &(t->C));
    double p = (a + b + c)/2.0;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main() {
    Point O = {}, A = {}, B = {}, C = {};
    cout << "Enter O coordinates: ";
    cin >> O.x >> O.y;
    cout << "Enter A coordinates: ";
    cin >> A.x >> A.y;
    cout << "Enter B coordinates: ";
    cin >> B.x >> B.y;
    cout << "Enter C coordinates: ";
    cin >> C.x >> C.y;
    Triangle main = {A, B, C};
    Triangle p1 = {A, B, O};
    Triangle p2 = {B, C, O};
    Triangle p3 = {A, C, O};
    double S = countArea(&main);
    double S1 = countArea(&p1);
    double S2 = countArea(&p2);
    double S3 = countArea(&p3);
    if(abs(S - S1 - S2 - S3) < 1e-5) {
        cout << "Point (" << O.x << ", " << O.y << ") ";
        cout << "is inside the triangle." << endl;
    }
    else {
        cout << "Point (" << O.x << ", " << O.y << ") ";
        cout << "is outside the triangle." << endl;
    }
    return 0;
}