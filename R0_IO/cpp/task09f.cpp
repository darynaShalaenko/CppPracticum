#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    double x2 = x * x;
    double x4 = x2 * x2;
    double x8 = x4 * x4;
    double x16 = x8 * x8;
    double x32 = x16 * x16;
    double x64 = x32 * x32;
    cout << "x^64 = " << x64 << endl;
    return 0;
}
