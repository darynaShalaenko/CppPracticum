#include <iostream>
using namespace std;

int main() {
    cout << "Task 3" << endl;
    double a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << endl;
    cout << "Enter b: ";
    cin >> b;
    cout << endl;
    double diff = a - b;
    double comp = a*b;
    cout << fixed;
    cout << "Difference: " << diff << endl;
    cout << "Composition: " << comp << endl;
    cout << defaultfloat;
    return 0;
}