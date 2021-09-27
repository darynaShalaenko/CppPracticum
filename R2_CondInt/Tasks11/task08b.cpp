#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a2, b2, c2;
    cout << "Enter a2, b2 and c2: ";
    cin >> a2 >> b2 >> c2;
    double x1 = (b2 - c2)/(b2 - a2);
    double x2 = (b2 + c2)/(a2 - b2);
    if(x1 == x2) {
        double y = (c2 - a2*x1)/b2;
        cout << "One solution: " << endl;
        cout << "x = " << x1 << endl;
        cout << "y = " << y << endl;
    }
    else {
        double y1 = (c2 - a2*x1)/b2;
        double y2 = (c2 - a2*x2)/b2;
        cout << "Two solutions: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "y1 = " << y1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "y2 = " << y2 << endl;
    }
}