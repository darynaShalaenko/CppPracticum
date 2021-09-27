#include <iostream>
using namespace std;

int main() {
    cout << "Task 1" << endl;
    double c;
    cout << "Enter t in celsius degrees: ";
    cin >> c;
    cout << endl;
    double f = 9.0*c/5.0 + 32.0;
    cout << "F = " << f << endl;
    return 0;
}
