#include <iostream>
#include <cmath>
using namespace std;

int sign(double x) {
    if(x > 0.0)
        return 1;
    if(x < 0.0)
        return -1;
    return 0;
}

int bisection(double xn, double xk, double eps, double f(double), double &res) {
    if( abs(f(xn)) <= eps ) {
        res =  xn;
        return 0;
    }
    if( abs(f(xk)) <= eps ) {
        res =  xk;
        return 0;
    }
    double dx, xi;
    while( (xk - xn) > (eps/10.0) ) {
        dx = (xk - xn)/2.0;
        xi = xn + dx;
        if( sign(f(xn)) != sign(f(xi)) )
            xk = xi;
        else
            xn = xi;
    }
    if( abs(f(xi)) <= eps ) {
        res = xi;
        return 0;
    }
    return 1;
}

int main() {
    double eps, xn = 0.001, xk = 1.5, res;
    cout << "Enter eps: ";
    cin >> eps;
    int status = bisection(xn, xk, eps, [](double x) {
        return tan(x) - x;
    }, res);
    if(status == 0)
        cout << "x = " << res << endl;
    else
        cout << "no x on this interval" << endl;
    return 0;
}