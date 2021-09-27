#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 2b" << endl;
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    double x_int;
    double x_fraction;
    x_fraction = modf(x, &x_int);
    double bigger = x_int + 1.0;
    double smaller;
    if (x_fraction == 0.0) smaller = x_int - 1.0;
    else smaller = x_int;
    double x_round = round(x);
    cout << "Integer part: " << x_int << endl;
    cout << "Fractional part: " << x_fraction << endl;
    cout << "Integer that is bigger then x: " << bigger << endl;
    cout << "Integer that is smaller then x: " << smaller << endl;
    cout << "Rounded value: " << x_round << endl;
    return 0;
}