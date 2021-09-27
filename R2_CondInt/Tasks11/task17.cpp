#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z, r;
    cout << "Enter point coordinates: ";
    cin >> x >> y >> z;
    cout << "Enter R: ";
    cin >> r;
    double l = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    if(l <= r)
        cout << "Point is inside the sphere.\n";
    else
        cout << "Point is outside the sphere.\n";
    return 0;
}