#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint64_t M, n, t, l, r1, r2;
    cout << "Enter M and n: ";
    cin >> M >> n;
    for(l = 0, t = M; t != 0; l++) t >>= 1u;
    r1 = M - ( (M >> (l-n)) << (l-n) );
    r2 = (M >> n) << n;
    cout << "r1: " << r1 << endl;
    cout << "r2(decimal): " << r2 << endl;
    cout << oct;
    cout << "r2(octal): " << r2 << endl;
    cout << dec;
    return 0;
}
