#include <iostream>
#include <cmath>
using namespace std;

double calc(int n, double x) {
    double res = x;
    for(int i = 0; i < n; i++) {
        res = sin(res);
    }
    return res;
}

int main() {
    int n;
    double x;
    cout << "Enter n and x: ";
    cin >> n >> x;
    cout << "Result: " << calc(n, x) << endl;
    return 0;
}
