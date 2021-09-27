#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    double x3 = x * x * x;
    double x6 = x3 * x3;
    double x12 = x6 * x6;
    double x15 = x12 * x3;
    cout << "x^15 = " << x15 << endl;
    return 0;
}
