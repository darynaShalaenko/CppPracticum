#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 8c" << endl;
    double x0, y0, a, b, c;
    cout << "Enter x0, y0: ";
    cin >> x0 >> y0;
    cout << endl;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double x = (a*b + b*c)/(1.0 - a*b);
    double y = -1*c - a*x;
    double l = sqrt( pow((x - x0) , 2) + pow((y - y0) , 2) );
    cout << "l = " << l << endl;
}
