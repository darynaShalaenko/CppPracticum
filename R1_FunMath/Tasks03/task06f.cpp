#include <iostream>
#include <cmath>
using namespace std;

double SoftPlus(double x) {
    return log(1 + exp(x));
}

double SoftPlus_derivative(double x) {
    return exp(x)/(exp(x) + 1);
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "SoftPlus(x) = " << SoftPlus(x) << endl;
    cout << "SoftPlus'(x) = " << SoftPlus_derivative(x) << endl;
    return 0;
}