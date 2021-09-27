#include <stdio.h>

using namespace std;

int main()
{
    unsigned int m, n;
    printf("m = ");
    scanf("%u", &m);
    printf("n = ");
    scanf("%u", &n);

    unsigned int n1 = m & n;
    unsigned int n2 = m | n;
    int i = 0, j = 0;
    printf("\n %u", n1);
    printf("\n %u", n2);

    while(n1 > 0)
    {
        if ((n1 % 2) == 1)
        {
            i++;
        }
        n1 = n1 >> 1;
    }
    while(n2 > 0)
    {
        if ((n2 % 2) == 0)
        {
            j++;
        }
        n2 = n2 >> 1;
    }
    printf("\n \n number of common 1s = %d", i);
    printf("\n number of common 1s and 0s = %d", i+j);

}
