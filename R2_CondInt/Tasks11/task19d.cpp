#include <iostream>
#include <cmath>
using namespace std;

double eLu(double x, double a) {
    if(x < 0) return a*(exp(x) - 1);
    return 0;
}

double eLu_derivative(double x, double a) {
    if(x < 0) return a*exp(x);
    return 0;
}

int main() {
    double x, a;
    cout << "Enter x and a: ";
    cin >> x >> a;
    cout << "eLu(x, a) = " << eLu(x, a) << endl;
    cout << "eLu'(x, a) = " << eLu_derivative(x, a) << endl;
    return 0;
}