#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, v, u, r;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << "Enter v, u and r: ";
    cin >> v >> u >> r;
    double ta = pow(b, 2) + pow(a, 2);
    double tb = -2*v*pow(b, 2) - 2*a*c + a*u*b;
    double tc1 = 2*u*c*b + pow(c, 2);
    double tc2 = pow(b, 2)*(pow(r, 2) - pow(v, 2) - pow(u, 2));
    double tc = tc1 - tc2;
    double D = pow(tb, 2) - 4*ta*tc;
    if(D < 0) {
        cout << "No intersections." << endl;
    }
    else if(D == 0) {
        cout << "One intersection: " << endl;
        double x1 = (-1*tb)/(2*ta);
        double y1 = (c - a*x1)/b;
        cout << "x1 = " << x1 << endl;
        cout << "y1 = " << y1 << endl;
    }
    else {
        cout << "Two intersections: " << endl;
        double x1 = (-1*tb + sqrt(D))/(2*ta);
        double y1 = (c - a*x1)/b;
        double x2 = (-1*tb - sqrt(D))/(2*ta);
        double y2 = (c - a*x2)/b;
        cout << "x1 = " << x1 << endl;
        cout << "y1 = " << y1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "y2 = " << y2 << endl;
    }
}