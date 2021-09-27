#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 6" << endl;
    double alpha, beta, gamma;
    cout << "Enter alpha, beta and gamma: ";
    cin >> alpha >> beta >> gamma;
    cout << endl;
    double r;
    cout << "Enter r: ";
    cin >> r;
    cout << endl;
    double x = r/tan(alpha/2.0);
    double y = r/tan(beta/2.0);
    double z = r/tan(gamma/2.0);
    double a = x + y;
    double b = y + z;
    double c = x + z;
    double p = (a + b + c)/2.0;
    double S = sqrt( p*(p - a)*(p - b)*(p - c) );
    cout << "S = " << S << endl;
    return 0;
}