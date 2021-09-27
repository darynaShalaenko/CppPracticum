#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, r;
    cout << "Enter a, b, c and r: ";
    cin >> a >> b >> c >> r;
    double y1 = sqrt(pow(r, 2) - pow(a, 2));
    double y2 = -1*y1;
    if( y1 >= b && y1 <= (b + pow(c, 2)) &&
        y2 >= b && y2 <= (b + pow(c, 2)) ) {
        cout << "Two intersections:" << endl;
        cout << "x1 = " << a << endl;
        cout << "y1 = " << y1 << endl;
        cout << "x2 = " << a << endl;
        cout << "y2 = " << y2 << endl;
    }
    else if( y1 >= b && y1 <= (b + pow(c, 2)) ) {
        cout << "One intersection:" << endl;
        cout << "x = " << a << endl;
        cout << "y = " << y1 << endl;
    }
    else if( y2 >= b && y2 <= (b + pow(c, 2)) ) {
        cout << "One intersection:" << endl;
        cout << "x = " << a << endl;
        cout << "y = " << y2 << endl;
    }
    else {
        cout << "No intersections." << endl;
    }
}