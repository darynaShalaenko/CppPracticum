#include <iostream>
#include <bitset>
using namespace std;

int main () {
    int a, i, j;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    cout << bitset<16>(a) << endl;
    int bj = a & (1<< (j-1));
    int bi = a & (1<< (i-1));
    a = a & (~(1<< (i-1))) & (~(1<< (j-1)));
    if (bj) a = a | (1<<(i - 1));
    if (bi) a = a | (1<< (j - 1));
    cout << bitset<16>(a)<< "\n"<< "Result dec: " << a << "\n"<< "hex: " << hex << a << endl;

    return 0;
}
