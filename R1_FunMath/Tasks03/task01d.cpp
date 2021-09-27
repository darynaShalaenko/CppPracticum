#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double x3= x*x*x;
    double x9 = x3*x3*x3;
    double y = x9 + x3 + 1;
    cout << "y = " << y << endl;
    return 0;
}
