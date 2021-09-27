#include <iostream>
#include <cmath>
using namespace std;

double calc(int n, double x) {
    double res = 1;
    for(int i = 1; i <= n; i++) {
        res += pow(x, pow(2, i));
    }
    return res;
}

int main() {
    cout << "Result (n = 4, x = 1): ";
    cout << calc(4, 1.0) << endl;
    return 0;
}
