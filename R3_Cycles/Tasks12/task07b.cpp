#include <iostream>
using namespace std;

int calc(int n) {
    int res = 1;
    for(int i = 1; i <= (2*n + 1); i += 2) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "(2n + 1)!! = " << calc(n) << endl;
    return 0;
}
