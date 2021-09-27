#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 12" << endl;
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double D = pow(b, 2) - 4*a*c;
    double x1 = ( -1*b + sqrt(D) )/( 2*a );
    double x2 = ( -1*b - sqrt(D) )/( 2*a );
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
}
