#include <iostream>
#include <cstdint>
using namespace std;

bool check(uint32_t n, uint32_t i = 32) {
    if(n == (1u << i)) return true;
    if(i == 0) return false;
    return check(n, (i-1));
}

int main() {
    uint32_t n;
    cout << "Enter n: ";
    cin >> n;
    check(n) ? cout << "yes" : cout << "no";
    cout << endl;
    return 0;
}
