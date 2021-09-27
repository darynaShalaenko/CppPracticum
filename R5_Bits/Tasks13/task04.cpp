#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint16_t n, left, right, res;
    cout << "Enter n: ";
    cin >> n;
    left = n >> 8u;
    right = n - (left << 8u);
    res = (right << 8u) | left;
    cout << "res(decimal): " << res << endl;
    cout << hex;
    cout << "res(hexadecimal): " << res << endl;
    cout << dec;
    return 0;
}
