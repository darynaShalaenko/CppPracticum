#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;
    cout << endl;
    double f = x + y;
    f += pow(x, 2) + pow(y, 2);
    f += pow(x, 3) + pow(y, 3);
    f += pow(x, 4) + pow(y, 4);
    cout << "f(x, y) = " << f << endl;
    return 0;
}
