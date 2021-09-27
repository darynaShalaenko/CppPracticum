#include <iostream>
using namespace std;

unsigned short sum(unsigned char a, unsigned char b) {
    return a*b;
}

int main() {
    unsigned short a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << endl;
    unsigned short res = sum(a, b);
    cout << "a*b = " << res << endl;
    return 0;
}
