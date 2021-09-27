#include <iostream>
using namespace std;

double onestep(double x) {
    if(x >= 0) return 1;
    return 0;
}

double onestep_derivative(double x) {
    return 0;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "onestep(x) = " << onestep(x) << endl;
    cout << "onestep'(x) = " << onestep_derivative(x) << endl;
    return 0;
}