#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

void printt(unsigned short n)
{
    cout << bitset < sizeof(n) * CHAR_BIT > (n) << endl;
}

unsigned short swap_bytes(unsigned short x) 
{
    unsigned short bitmask = 0x00FF;
    unsigned short temp = x & bitmask;
    x = x >> 8;
    temp = temp << 8;
    x = x | temp;
    return x;
}


int main()
{
    unsigned short x,k;
    printf("Enter x ");
    scanf("%d",&x);
    printt(x);

    k = swap_bytes(x);

    printt(k);

    printf("N в 16-му вигляді = %X N в 10-му вигляді = %d",k,k);
}
