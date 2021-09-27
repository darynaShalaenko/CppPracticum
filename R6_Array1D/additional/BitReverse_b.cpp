#include <iostream>
#include <cstdint>
using namespace std;

uint32_t BitReverse(uint32_t n) {
    uint32_t r = 0;
    int i, j;
    for(i = 31; i > -1; i--)
        if((n >> i) & 1) break;
    for(j = i; j > -1; j--) {
        if((n >> j) & 1) r |= (1 << (i-j));
        else r &= ~(1 << (i-j));
    }
    return r;
}

int main() {
    uint32_t n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    cout << "Results: " << endl;
    for(uint32_t i = n; i <= m; i++)
        cout << BitReverse(i) << endl;
    return 0;
}
