#include <iostream>
#include <cmath>
using namespace std;

double Rosenbrock2d(double x, double y) {
    return 100*pow(( pow(x, 2) - y ), 2) + pow((x - 1), 2);
}

int main() {
    double x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;
    cout << endl;
    double res = Rosenbrock2d(x, y);
    cout << "Rosenbrock2d(x, y) = " << res << endl;
    return 0;
}
