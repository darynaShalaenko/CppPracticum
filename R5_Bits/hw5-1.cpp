#include <stdio.h>

using namespace std;

int main()
{
    unsigned int n, i, j;
    printf("M = ");
    scanf("%u", &n);
    printf("i = ");
    scanf("%u", &i);
    printf("j = ");
    scanf("%u", &j);


    if (((n >> i)%2 == 1) && ((n >> j)%2 == 0))
    {
        n |= (1 << j);
        n &= ~((1 << (n+1)) | (1 << i));
    }
    else if (((n >> i)%2 == 0) && ((n >> j)%2 == 1))
    {
        n |= (1 << i);
        n &= ~((1 << (n+1)) | (1 << j));
    }

    printf("%u \n", n);
    printf("%x", n);


















}
