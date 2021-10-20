#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;

    int counter = 0, max_counter=0;
    cout << bitset<64> (n) << endl;
    while (n > 0)
    {
        if (n & 1 == 1) counter++;
        else
        {
            if (counter > max_counter)
            {
                max_counter = counter;
            }
            counter = 0;
        }
        n = n >> 1;
    }
    if (counter > max_counter)
            {
                max_counter = counter;
            }
    cout << max_counter;
}
