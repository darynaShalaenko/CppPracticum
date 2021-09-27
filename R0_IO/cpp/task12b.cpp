#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "  x  |  1  |  2  |  3  |  4  |  5  " << endl;
    cout << "------+-----+-----+-----+-----+-----" << endl;
    cout << fixed << setprecision(2);
    cout << "F(x) | " ;
    cout << sqrt(1) << " | ";
    cout << sqrt(2) << " | ";
    cout << sqrt(3) << " | ";
    cout << sqrt(4) << " | ";
    cout << sqrt(5) << " ";
    cout << endl;
    cout << defaultfloat;
    return 0;
}
