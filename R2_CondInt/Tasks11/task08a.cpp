#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a1, b1, c1, a2, b2, c2;
    cout << "Enter a1, b1 and c1: ";
    cin >> a1 >> b1 >> c1;
    cout << "Enter a2, b2 and c2: ";
    cin >> a2 >> b2 >> c2;
    double x = (b2*c1 + c2)/(a1*b2 - a2*b1);
    double y = (c1 - a1*x)/b1;
    cout << "One solution: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}