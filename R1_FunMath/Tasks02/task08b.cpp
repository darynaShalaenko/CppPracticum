#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 8b" << endl;
    double x0, y0, a, b, c;
    cout << "Enter x0, y0: ";
    cin >> x0 >> y0;
    cout << endl;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double l = abs(a*x0 + b*y0 + c)/sqrt(a*a + b*b);
    cout << "l = " << l << endl;
}
