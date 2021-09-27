#include <iostream>
using namespace std;

double ReLu(double x) {
    if(x > 0) return x;
    return 0;
}

double ReLu_derivative(double x) {
    if(x > 0) return 1;
    return 0;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "ReLu(x) = " << ReLu(x) << endl;
    cout << "ReLu'(x) = " << ReLu_derivative(x) << endl;
    return 0;
}