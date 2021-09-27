#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    double x2 = x * x;
    double x6 = x2 * x2 * x2;
    double x12 = x6 * x6;
    double x14 = x12 * x2;
    double x28 = x14 * x14;
    cout << "x^28 = " << x28 << endl;
    return 0;
}
