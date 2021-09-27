#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double a = 3.0;
    const double b = 3.5 + 3*pow(2, -111);
    const double c = 3.5 + 3*pow(2, -111);
    double P = a + b + c;
    double p = P/2.0;
    double S = sqrt( p*(p - a)*(p - b)*(p - c) );
    cout << "P = " << P << endl;
    cout << "S = " << S << endl;
    return 0;
}
