#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint64_t M, r = 1;
    uint16_t j;
    cout << "Enter M and j: ";
    cin >> M >> j;
    r <<= j;
    r ^= M;
    cout << "res(decimal): " << r << endl;
    cout << hex;
    cout << "res(hexadecimal): " << r << endl;
    cout << dec;
    return 0;
}
