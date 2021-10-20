#include <iostream>
#include <bitset>
#include <stdint.h>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    cout << bitset<64> (n) << endl;
    unsigned res = 0;
    while (n != 0)
    {
        if (!(n & 1)) res++;
        n = n >> 1;
    }
    cout << res << endl;
}
