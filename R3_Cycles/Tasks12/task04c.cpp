#include <iostream>
#include <cmath>
using namespace std;

double calc(unsigned int n, double x) {
    double res = x;
    for(int i = 2; i <= n; i++) {
        res += pow((i*x), i);
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
