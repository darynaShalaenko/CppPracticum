#include <iostream>
using namespace std;

double pleakyReLu(double x, double a) {
    if(x < 0) return a*x;
    return 0;
}

double pleakyReLu_derivative(double x, double a) {
    if(x < 0) return a;
    return 0;
}

int main() {
    double x, a;
    cout << "Enter x and a: ";
    cin >> x >> a;
    cout << "pleakyReLu(x, a) = " << pleakyReLu(x, a) << endl;
    cout << "pleakyReLu'(x, a) = " << pleakyReLu_derivative(x, a) << endl;
    return 0;
}