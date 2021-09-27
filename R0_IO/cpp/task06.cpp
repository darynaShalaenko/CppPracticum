#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double G = 6.673 * pow(10, -11);
    double m1, m2, r;
    cout << "Enter m1: ";
    cin >> m1;
    cout << endl;
    cout << "Enter m2: ";
    cin >> m2;
    cout << endl;
    cout << "Enter r: ";
    cin >> r;
    cout << endl;
    double F = G * m1 * m2 / pow(r, 2);
    cout << "F = ";
    cout << scientific;
    cout << F << endl;
    cout << defaultfloat;
    return 0;
}
