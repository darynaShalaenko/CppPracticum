#include <iostream>
using namespace std;

double calcV(int n);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Vn = " << calcV(n) << endl;
    return 0;
}

double calcV(int n) {
    double v1 = 1.0, v2 = 1.0;
    double u1 = 0.0, u2 = 0.0;
    for(int i = 2; i <= n; i++) {
        double v = (u1 - v1)/(abs(u2 + v1) + 2.0);
        double u = (u1 - u2*v1 - v2)/(1.0 + u1*u1 + v1*v1);
        v2 = v1, v1 = v;
        u2 = u1, u1 = u;
    }
    return v1;
}