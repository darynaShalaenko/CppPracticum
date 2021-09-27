#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    double res1 = abs(x);
    double res2 = abs(abs(x) - 1) - 1;
    double res3;
    if(x > 0) res3 = 1;
    else if(x < 0) res3 = -1;
    else res3 = 0;
    double res4 = sin(abs(x));
    cout << "|x| = " << res1 << endl;
    cout << "||x| - 1| - 1 = " << res2 << endl;
    cout << "sign(x) = " << res3 << endl;
    cout << "sin|x| = " << res4 << endl;
    return 0;
}