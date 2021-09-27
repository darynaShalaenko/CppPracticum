#include <iostream>
using namespace std;

int calc(int n) {
    int res = 1;
    for(int i = 2; i <= 2*n; i += 2) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "(2n)!! = " << calc(n) << endl;
    return 0;
}
