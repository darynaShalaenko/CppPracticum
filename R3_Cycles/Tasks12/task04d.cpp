#include <iostream>
#include <cmath>
using namespace std;

double calc(unsigned int n, double x) {
    double res = 1;
    for(int i = 1; i <= n; i++) {
        res += pow(sin(x), i);
    }
    return res;
}

int main() {
    unsigned int n;
    double x;
    cout << "Enter n and x: ";
    cin >> n >> x;
    cout << "Result (n = " << n << ", x = " << x << "): ";
    cout << calc(n, x) << endl;
    return 0;
}
