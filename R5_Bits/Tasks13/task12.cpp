#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

void in(uint32_t &M, uint32_t &i, uint32_t &j) {
    cout << "Enter M, i and j: ";
    cin >> M >> i >> j;
}

uint32_t change(uint32_t M, uint32_t i, uint32_t j) {
    bitset<32> b = M;
    bool t = b[i];
    b[i] = b[j];
    b[j] = t;
    return b.to_ulong();
}

void out(uint32_t res) {
    cout << "res(decimal): " << res << endl;
    cout << hex;
    cout << "res(hexadecimal): " << res << endl;
    cout << dec;
}

int main() {
    uint32_t M, i, j;
    in(M, i, j);
    M = change(M, i, j);
    out(M);
    return 0;
}
