#include <iostream>
using namespace std;

double calcV(int i);
double calcU(int i);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Vn = " << calcV(n) << endl;
    return 0;
}

double calcV(int i) {
    if(i == 0 || i == 1) return 1.0;
    double u1 = calcU(i-1);
    double u2 = calcU(i-2);
    double v1 = calcV(i-1);
    return (u1 - v1)/(abs(u2 + v1) + 2.0);
}

double calcU(int i) {
    if(i == 0 || i == 1) return 0.0;
    double u1 = calcU(i-1);
    double u2 = calcU(i-2);
    double v1 = calcV(i-1);
    double v2 = calcV(i-2);
    return (u1 - u2*v1 - v2)/(1.0 + u1*u1 + v1*v1);
}