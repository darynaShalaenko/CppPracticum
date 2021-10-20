#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

int main() {
    int16_t n = 0b0010001100011000;
    cout << bitset<16>(n) <<  endl;
    cout << bitset<16>(~n + 1) <<  endl;
    cout << bitset<16>(-n) <<  endl;
    cout << bitset<16>(n & (-n)) <<  endl;
    return 0;
}
