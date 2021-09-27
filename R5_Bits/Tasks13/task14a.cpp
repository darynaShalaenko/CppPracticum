#include <iostream>
#include <cstdint>
using namespace std;

bool check(uint32_t n) {
    for(uint32_t i = 32; i > 0; i--)
        if(n == (1u << i)) return true;
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
