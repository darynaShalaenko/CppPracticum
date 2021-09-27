#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, t;
    cout << "Enter a: ";
    cin >> a;
    cout << endl;
    cout << "Enter t: ";
    cin >> t;
    cout << endl;
    double S = a * pow(t, 2) / 2.0;
    cout << "S = " << S << endl;
    return 0;
}
