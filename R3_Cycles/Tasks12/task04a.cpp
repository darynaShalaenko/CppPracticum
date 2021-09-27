#include <iostream>
#include <cmath>
using namespace std;

double calc(unsigned int n, double x) {
    double res = 0;
    for(int i = 1; i <= n; i++) {
        res += i*pow(x, (n - 1));
    }
    return res;
}

int main() {
    unsigned int n;
    double x;
    cout << "Enter n and x: ";
    cin >> n >> x;
    if(x < 1.0 && x > 0.0) {
        cout << "Result (n = " << n << ", x = " << x << "): ";
        cout << calc(n, x) << endl;
    }
    else {
        cout << "x should be greater than 0 and less than 1." << endl;
    }
    return 0;
}
