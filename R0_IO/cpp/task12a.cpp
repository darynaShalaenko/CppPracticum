#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "   x  |   1  |   2  |   3  |   4  |   5  " << endl;
    cout << "------+------+------+------+------+------" << endl;
    cout << fixed << setprecision(2);
    cout << " F(x) | " ;
    cout << exp(-1*1) << " | ";
    cout << exp(-2*2) << " | ";
    cout << exp(-3*3) << " | ";
    cout << exp(-4*4) << " | ";
    cout << exp(-5*5) << " ";
    cout << endl;
    cout << defaultfloat;
    return 0;
}
