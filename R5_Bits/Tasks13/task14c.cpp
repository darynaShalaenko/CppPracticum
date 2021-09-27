#include <iostream>
#include <cstdint>
using namespace std;

bool check(uint32_t n) {
    if((n & (n-1)) == 0) return true;
    return false;
}

int main() {
    uint32_t n;
    cout << "Enter n: ";
    cin >> n;
    check(n) ? cout << "yes" : cout << "no";
    cout << endl;
    return 0;
}
