#include <iostream>
#include <cmath>
using namespace std;

double sigmweight(double x) {
    return x/(1 + exp(-1*x));
}

double sigmweight_derivative(double x) {
    double t1 = x*exp(-1*x);
    double t2 = 1 + exp(-1*x);
    return t1/pow(t2, 2) + 1.0/t2;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "sigmweight(x) = " << sigmweight(x) << endl;
    cout << "sigmweight'(x) = " << sigmweight_derivative(x) << endl;
    return 0;
}