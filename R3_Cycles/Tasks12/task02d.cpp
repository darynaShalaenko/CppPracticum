#include <iostream>
#include <cmath>
using namespace std;

double calc(int n, double x, double y) {
    double res = 0;
    for(int i = 0; i <= n; i++) {
        res += pow(x, pow(2, i))*pow(y, i);
    }
    return res;
}

int main() {
    cout << "Result (n = 4, x = 1), y = 2: ";
    cout << calc(4, 1.0, 2.0) << endl;
    return 0;
}
