#include <iostream>
using namespace std;

bool a (unsigned int n) {
    if(n % 2 == 0) return true;
    return false;
}

bool b (unsigned int n) {
    if(n % 10 == 0) return true;
    return false;
}

bool c (int n, unsigned int m) {
    if(n % m == 0) return true;
    return false;
}

bool d (unsigned int n, unsigned int k, unsigned int m) {
    if(n % m == 0 && k % m == 0) return true;
    return false;
}

bool e (unsigned int n) {
    unsigned int a  = n % 10;
    unsigned int b = n/10;
    unsigned int s = a + b;
    if(s % 10 != s) return true;
    return false;
}

bool f (int x, int y) {
    if(x - y > 6) return true;
    return false;
}

bool g (int x, int y, int z) {
    if(x > 100 || y > 100 || z > 100) return true;
    return false;
}

bool h (int x, int y, int z) {
    if(x < 1000 && y >= 1000 && z >= 1000) return true;
    if(y < 1000 && x >= 1000 && z >= 1000) return true;
    if(z < 1000 && x >= 1000 && y >= 1000) return true;
    return false;
}

int main() {
    int m, n, k, x, y, z;
    cout << "Enter m, n and k: ";
    cin >> m >> n >> k;
    cout << "Enter x, y and z: ";
    cin >> x >> y >> z;
    cout << "a(n) = " << a(n) << endl;
    cout << "b(n) = " << b(n) << endl;
    cout << "c(n, m) = " << c(n, m) << endl;
    cout << "d(n, k, m) = " << d(n, k, m) << endl;
    cout << "e(n) = " << e(n) << endl;
    cout << "f(x, y) = " << f(x, y) << endl;
    cout << "g(x, y, z) = " << g(x, y, z) << endl;
    cout << "h(x, y, z) = " << h(x, y, z) << endl;
    return 0;
}