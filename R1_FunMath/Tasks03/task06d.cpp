#include <iostream>
#include <cmath>
using namespace std;

double arctg(double x) {
    return atan(x);
}

double arctg_derivative(double x) {
    return 1.0/(pow(x, 2) + 1);
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "arctg(x) = " << arctg(x) << endl;
    cout << "arctg'(x) = " << arctg_derivative(x) << endl;
    return 0;
}