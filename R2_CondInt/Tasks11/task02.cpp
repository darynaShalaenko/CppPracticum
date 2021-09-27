#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    a = abs(a);
    b = abs(b);
    c = abs(c);
    if(a == b && b == c) {
        cout << "all numbers are equal";
        return 0;
    }
    if(a > b && a > c)
        cout << "module a is greatest" << endl;
    else if(b > a && b > c)
        cout << "module b is greatest" << endl;
    else if(c > a && c > b)
        cout << "module c is greatest" << endl;
    if(a < b && a < c)
        cout << "module a is lowest" << endl;
    else if(b < a && b < c)
        cout << "module b is lowest" << endl;
    else if(c < a && c < b)
        cout << "module c is lowest" << endl;
    return 0;
}
