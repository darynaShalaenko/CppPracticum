#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double D = pow(b, 2) - 4*a*c;
    if(D < 0) {
        cout << "No solutions." << endl;
    }
    else if(D == 0) {
        double x1 = (-1*b)/(2*a);
        if(x1 == 0) {
            cout << "One solution: " << endl;
            cout << "x1 = " << 0 << endl;
        }
        else {
            cout << "Two solutions: " << endl;
            cout << "x1 = " << sqrt(x1) << endl;
            cout << "x2 = " << -1*sqrt(x1) << endl;
        }
    }
    else {
        double x1 = (-1*b + sqrt(D))/(2*a);
        double x2 = (-1*b - sqrt(D))/(2*a);
        if(x1 == 0 && x2 == 0) {
            cout << "One solution: " << endl;
            cout << "x1 = " << 0 << endl;
        }
        else if(x1 == 0) {
            cout << "Three solutions: " << endl;
            cout << "x1 = " << sqrt(x2) << endl;
            cout << "x2 = " << -1*sqrt(x2) << endl;
            cout << "x3 = " << 0 << endl;
        }
        else if(x2 == 0) {
            cout << "Three solutions: " << endl;
            cout << "x1 = " << sqrt(x1) << endl;
            cout << "x2 = " << -1*sqrt(x1) << endl;
            cout << "x3 = " << 0 << endl;
        }
        else {
            cout << "Four solutions: " << endl;
            cout << "x1 = " << sqrt(x1) << endl;
            cout << "x2 = " << -1*sqrt(x1) << endl;
            cout << "x3 = " << sqrt(x2) << endl;
            cout << "x3 = " << -1*sqrt(x2) << endl;
        }
    }
}