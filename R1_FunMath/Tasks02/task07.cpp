#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 7" << endl;
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double p = (a + b + c)/2.0;
    double R = a*b*c/(4*sqrt( p*(p - a)*(p - b)*(p - c) ));
    double sinAlpha = a/(2*R);
    double sinBeta = b/(2*R);
    double sinGamma = c/(2*R);
    double alpha = asin(sinAlpha);
    double beta = asin(sinBeta);
    double gamma = asin(sinGamma);
    double alphaDegrees = (alpha/M_PI)*180;
    double betaDegrees = (beta/M_PI)*180;
    double gammaDegrees = (gamma/M_PI)*180;
    cout << "alpha = " << alpha << " = ";
    cout << alphaDegrees << "°" << endl;
    cout << "beta = " << beta << " = ";
    cout << betaDegrees << "°" << endl;
    cout << "gamma = " << gamma << " = ";
    cout << gammaDegrees << "°" << endl;
}
