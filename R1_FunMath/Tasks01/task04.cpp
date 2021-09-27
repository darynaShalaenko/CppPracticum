#include <iostream>
using namespace std;

int main() {
    cout << "Task 4" << endl;
    double a, b;
    cout << "Enter a and b:" << endl;
    cin >> a >> b;
    double arithm = (a + b)/2.0;
    double harm = 2.0/(1.0/a + 1.0/b);
    cout << scientific;
    cout << "Scientific representation:" << endl;
    cout << "Arithmetic mean: " << arithm << endl;
    cout << "Harmonic mean: " << harm << endl;
    cout << endl;
    cout << fixed;
    cout << "Decimal representation:" << endl;
    cout << "Arithmetic mean: " << arithm << endl;
    cout << "Harmonic mean: " << harm << endl;
    cout << defaultfloat;
    return 0;
}