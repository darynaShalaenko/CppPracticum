#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <bitset>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;
    cout << bitset<32> (n) << endl;

    unsigned j;
    cin >> j;

    n = ~ ( ~n | (1<<j) );

    cout << bitset<32> (n) << endl;
    cout << n << endl;
    cout << hex << n;
}
