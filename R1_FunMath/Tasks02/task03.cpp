#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 3" << endl;
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double p = (a + b + c)/2.0;
    double S = sqrt( p*(p - a)*(p - b)*(p - c) );
    cout << "S = " << S << endl;
    return 0;
}
