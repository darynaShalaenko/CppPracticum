#include <iostream>
#include <cmath>
using namespace std;

double countLength(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double triangleArea(double a, double b, double c) {
    double p = (a + b + c)/2.0;
    return sqrt( p*(p - a)*(p - b)*(p - c) );
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cout << endl;
    double a = countLength(x1, y1, x2, y2);
    double b = countLength(x1, y1, x3, y3);
    double c = countLength(x2, y2, x3, y3);
    double S = triangleArea(a, b, c);
    cout << "S = " << S << endl;
    return 0;
}