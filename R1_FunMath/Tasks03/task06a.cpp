#include <iostream>
#include <cmath>
using namespace std;

double th(double x) {
    return (exp(x) - exp(-1*x))/(exp(x) + exp(-1*x));
}

double th_derivative(double x) {
    double t1 = -1*(exp(x)) + exp(-1*x);
    double t2 = exp(x) - exp(-1*x);
    double t3 = exp(x) + exp(-1*x);
    return (t1*t2)/pow(t3, 2) + 1;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "th(x) = " << th(x) << endl;
    cout << "th'(x) = " << th_derivative(x) << endl;
    return 0;
}