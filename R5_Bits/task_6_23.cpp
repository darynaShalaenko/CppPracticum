#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<32> foo(0xDEADBEEF);
    auto n = foo.count();

    cout << foo << endl;
    cout << n << " ones in" << endl;
    cout << foo.size() - n << " zeroes in" << endl;

    return 0;
}
