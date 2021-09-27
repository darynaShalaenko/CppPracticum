#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint8_t n;
    cout << "Enter n: ";
    cin >> n;
    uint64_t res = 1LU << n;
    cout << "res: " << res << endl;
    return 0;
}
