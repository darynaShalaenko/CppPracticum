#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double m, v;
    cout << "Enter m: ";
    cin >> m;
    cout << endl;
    cout << "Enter v: ";
    cin >> v;
    cout << endl;
    double E = m * pow(v, 2);
    cout << "E = " << E << endl;
    return 0;
}
