#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

uint32_t BitReverse(uint32_t n) {
    const int l = 32;
    bitset<l> b = n;
    bitset<l> r = 0;
    int i, j;
    for(i = (l - 1); i > -1; i--)
        if(b[i] == 1) break;
    for(j = i; j > -1; j--)
        r[i-j] = b[j];
    return r.to_ulong();
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
