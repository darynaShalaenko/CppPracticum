#include <iostream>
#include <vector>
using namespace std;

double generate(double un1, double xk, double f(double)) {
    return un1 - (f(un1)/(f(xk) - f(un1)))*(xk - un1);
}

double secant(double xn, double xk, double eps, double f(double)) {
    vector<double> s {xn, generate(xn, xk, f)};
    while(abs(s.at(s.size()-1) - s.at(s.size()-2)) >= eps) {
        double un1 = s.at(s.size()-1);
        s.push_back(generate(un1, xk, f));
    }
    return s.at(s.size()-1);
}

int main() {
    double eps, xn = 0.0, xk = 2.0;
    cout << "Enter eps: "; cin >> eps;
    double res = secant(xn, xk, eps, [](double x) {
        return x*x*x + 4.0*x*x + x - 6.0;
    });
    cout << "x = " << res << endl;
    return 0;
}