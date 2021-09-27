#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double x2 = x*x;
    double y = (x2 + 1)*(x2 + x) + 1;
    cout << "y = " << y << endl;
    return 0;
}
