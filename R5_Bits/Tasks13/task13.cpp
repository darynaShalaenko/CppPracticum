#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

uint32_t count(uint32_t n) {
    bitset<32> b = n;
    uint32_t c = 0;
    for(uint32_t i = 0; i < 32; i++)
        if(b[i] == 1) c++;
    return c;
}

int main() {
    uint32_t n;
    cout << "Enter n: ";
    cin >> n;
    uint32_t res = count(n);
    cout << "res: " << res << endl;
    return 0;
}
