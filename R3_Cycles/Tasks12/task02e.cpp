#include <iostream>
#include <cmath>
using namespace std;

double calc(int n, double x) {
    double res = 0;
    for(int i = 1; i <= n; i++) {
        res += pow(x, pow(i, 2));
    }
    return res;
}

int main() {
    cout << "Result (n = 5, x = -1): ";
    cout << calc(5, -1.0) << endl;
    return 0;
}
