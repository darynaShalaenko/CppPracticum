#include <iostream>
#include <cmath>
using namespace std;

double Softsign(double x) {
    return x/(1 + abs(x));
}

double Softsign_derivative(double x) {
    if(x > 0) {
        double t1 = -1*x/pow((x + 1), 2);
        double t2 = 1.0/(x + 1);
        return t1 + t2;
    }
    else if (x < 0) {
        double t1 = x/pow((1 - x), 2);
        double t2 = 1.0/(1 - x);
        return t1 + t2;
    }
    else return 0;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "Softsign(x) = " << Softsign(x) << endl;
    cout << "Softsign'(x) = " << Softsign_derivative(x) << endl;
    return 0;
}