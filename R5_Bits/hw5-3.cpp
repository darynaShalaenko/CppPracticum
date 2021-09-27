#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    unsigned int n, n1, res, i = 0;
    printf("n = ");
    scanf("%u", &n);
    n1 = n;

    if (n1 == 0)
    {
        res = 1;
    }
    else
    {
        while (n1 > 0)
        {
            i++;
            n1 >>= 1;
        }
        printf("%u", i);

        int n0 = ~0;
        n = ~n;
        printf("\n %u", n);
        n <<= n0-i+1;
        printf("\n %u", n);
        n >>= n0-i+1;
        printf("\n %u", n);


    }
}
