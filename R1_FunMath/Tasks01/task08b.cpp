#include <iostream>
using namespace std;

int main() {
    double a;
    cout << "Enter a: ";
    cin >> a;
    cout << endl;
    if(a > 100) {
        cout << "a should be less than 100.";
        return 0;
    }
    cout << a << "-----------" << a << endl;
    cout << "|     " << a << "     |" << endl;
    cout << a << "-----------" << a << endl;
    return 0;
}