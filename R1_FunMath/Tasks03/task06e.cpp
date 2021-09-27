#include <iostream>
#include <cmath>
using namespace std;

double gauss(double x) {
    return exp(-1*pow(x, 2));
}

double gauss_derivative(double x) {
    return -2*x*exp(-1*pow(x, 2));
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "gauss(x) = " << gauss(x) << endl;
    cout << "gauss'(x) = " << gauss_derivative(x) << endl;
    return 0;
}