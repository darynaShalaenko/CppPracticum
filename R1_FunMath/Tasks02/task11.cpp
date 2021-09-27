#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 11" << endl;
    double R1, R2;
    cout << "Enter r and R: ";
    cin >> R1 >> R2;
    cout << endl;
    double r = (R2 - R1)/2.0;
    double R = R1 + r;
    double V = 2*pow(M_PI, 2)*R*pow(r, 2);
    cout << "V = " << V << endl;
}
