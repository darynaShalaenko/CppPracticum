#include <iostream>
#include <cmath>
using namespace std;

double calc(int n, double x) {
    double res = 0;
    for(int i = 0; i <= n; i++) {
        res += pow(x, i);
    }
    return res;
}

int main() {
    cout << "Result (n = 3, x = 2): ";
    cout << calc(3, 2.0) << endl;
    return 0;
}
