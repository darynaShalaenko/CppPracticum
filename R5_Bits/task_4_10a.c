#include <iostream>
#include <bitset>
#include <climits>
#include <math.h>
using namespace std;

void printt(int n)
{
    cout << bitset < sizeof(n) * CHAR_BIT > (n) << endl;
}


int swap_bytes(int x) 
{
    int bitmask = 0x00FF;
    int temp = x & bitmask;
    x = x >> 8;
    temp = temp << (sizeof(x)-1) * 8;
    x = x | temp;
    return x;
}


int main()
{
    int x,k;
    printf("Enter x ");
    scanf("%d",&x);
    cout << "before: " ;
    printt(x);

    k = swap_bytes(x);
    cout << "after: ";
    printt(k);

    printf("N в 16-му вигляді = %X, N в 10-му вигляді = %d",k,k);

