#include <iostream>
#include <cmath>
using namespace std;

double isReLu(double x, double a) {
    if(x < 0) x/(sqrt(1 + a*pow(x, 2)));
    return x;
}

double isReLu_derivative(double x, double a) {
    if(x < 0) return pow(( 1.0/(sqrt(1 + a*pow(x, 2))) ), 3);
    return 1;
}

int main() {
    double x, a;
    cout << "Enter x and a: ";
    cin >> x >> a;
    cout << "isReLu(x, a) = " << isReLu(x, a) << endl;
    cout << "isReLu'(x, a) = " << isReLu_derivative(x, a) << endl;
    return 0;
}