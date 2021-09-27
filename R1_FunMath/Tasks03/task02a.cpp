#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;
    cout << endl;
    double f = pow(x, 3) + 3*pow(x, 2)*y + 3*x*pow(y, 2) + pow(y, 3);
    cout << "f(x, y) = " << f << endl;
    return 0;
}
