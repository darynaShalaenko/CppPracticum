#include <iostream>
#include <cmath>
using namespace std;

double SoftExponential(double x, double a) {
    if(a < 0) return (-1*log(1 - a*(x + a)))/a;
    if(a > 0) return (exp(a*x) - 1)/a;
    return x;
}

double SoftExponential_derivative(double x, double a) {
    if(x < 0) return 1.0/(1 - a*(a + x));
    return exp(a*x);
}

int main() {
    double x, a;
    cout << "Enter x and a: ";
    cin >> x >> a;
    cout << "SoftExponential(x, a) = ";
    cout << SoftExponential(x, a) << endl;
    cout << "SoftExponential'(x, a) = ";
    cout << SoftExponential_derivative(x, a) << endl;
    return 0;
}