#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double x2 = x*x;
    double x4 = x2*x2;
    double y = x4 + 2*x2 + 1;
    cout << "y = " << y << endl;
    return 0;
}
