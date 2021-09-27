#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double x2 = x*x;
    double x3 = x2*x;
    double x4 = x3*x;
    double x5 = x4*x;
    double y = x5 + 5*(x4 + x) + 10*(x3 + x2) + 1;
    cout << "y = " << y << endl;
    return 0;
}
