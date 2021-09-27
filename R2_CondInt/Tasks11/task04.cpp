#include <iostream>
using namespace std;

int main() {
    double x, y, z, a;
    cout << "Enter x, y and z: ";
    cin >> x >> y >> z;
    cout << "Enter a: ";
    cin >> a;
    int d, s;
    if(x == y && y == z) {
        d = 1;
        s = 3;
    }
    else if(x == y || x == z || y == z) {
        d = 2;
        s = 2;
    }
    else {
        d = 3;
        s = 1;
    }
    double m = (x + y + z)/3.0;
    int bm = 0, ba = 0;
    if(x > m) bm++;
    if(y > m) bm++;
    if(z > m) bm++;
    if(x > a) ba++;
    if(y > a) ba++;
    if(z > a) ba++;
    cout << "different: " << d << endl;
    cout << "same: " << s << endl;
    cout << "bigger than mean: " << bm << endl;
    cout << "bigger than a: " << ba << endl;
}
