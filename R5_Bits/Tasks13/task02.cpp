#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint32_t n, k, r = 1;
    cout << "Enter n and k: ";
    cin >> n >> k;
    r <<= k;
    r |= n;
    cout << "res: " << r << endl;
    return 0;
}
