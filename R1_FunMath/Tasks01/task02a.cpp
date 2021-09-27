#include <iostream>
using namespace std;

int main() {
    cout << "Task 2a" << endl;
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    int x_int = static_cast<int>(x);
    double x_fraction = x - x_int;
    int bigger = x_int + 1;
    int smaller;
    if (x_fraction == 0.0) smaller = x_int - 1;
    else smaller = x_int;
    int x_round;
    if (x_fraction < 0.5) x_round = x_int;
    else x_round = x_int + 1;
    cout << "Integer part: " << x_int << endl;
    cout << "Fractional part: " << x_fraction << endl;
    cout << "Integer that is bigger then x: " << bigger << endl;
    cout << "Integer that is smaller then x: " << smaller << endl;
    cout << "Rounded value: " << x_round << endl;
    return 0;
}