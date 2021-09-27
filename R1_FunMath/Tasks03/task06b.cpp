#include <iostream>
#include <cmath>
using namespace std;

double Bent(double x) {
    double t1 = sqrt( pow(x, 2) + 1 );
    return (t1 - 1)/2.0 + x;
}

double Bent_derivative(double x) {
    double t1 = sqrt( pow(x, 2) + 1 );
    return x/(2*t1) + 1;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "Bent(x) = " << Bent(x) << endl;
    cout << "Bent'(x) = " << Bent_derivative(x) << endl;
    return 0;
}