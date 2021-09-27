#include <iostream>
#include <cmath>
using namespace std;

double invsqrt(double x, double alpha) {
    return x/sqrt(1 + alpha*pow(x, 2));
}

double invsqrt_derivative(double x, double alpha) {
    double t1 = alpha*pow(x, 2);
    double t2 = pow((t1 + 1), 1.5);
    double t3 = sqrt(t1 + 1);
    return (-1*t1)/t2 + 1.0/t3;
}

int main() {
    double x, alpha;
    cout << "Enter x, alpha: ";
    cin >> x >> alpha;
    cout << endl;
    cout << "invsqrt(x, alpha) = " << invsqrt(x, alpha) << endl;
    cout << "invsqrt'(x, alpha) = " << invsqrt_derivative(x, alpha) << endl;
    return 0;
}