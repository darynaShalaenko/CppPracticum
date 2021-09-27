#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 8a" << endl;
    double x0, y0, x, y;
    cout << "Enter x0, y0: ";
    cin >> x0 >> y0;
    cout << endl;
    cout << "Enter x, y: ";
    cin >> x >> y;
    cout << endl;
    double l = sqrt( pow((x - x0) , 2) + pow((y - y0) , 2) );
    cout << "l = " << l << endl;
}
