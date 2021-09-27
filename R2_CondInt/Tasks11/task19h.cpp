#include <iostream>
#include <cmath>
using namespace std;

double sinc(double x) {
    if(x != 0) return sin(x)/x;
    return 1;
}

double sinc_derivative(double x) {
    if(x != 0) return ( (cos(x)/x) - (sin(x)/pow(x, 2)) );
    return 0;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "sinc(x) = " << sinc(x) << endl;
    cout << "sinc'(x) = " << sinc_derivative(x) << endl;
    return 0;
}