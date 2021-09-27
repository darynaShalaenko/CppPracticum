#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    unsigned long int Fn,Fn1,Fn2;
    int n;
    printf("n = ");
    scanf("%d", &n);

    Fn1 = 1;
    Fn2 = 1;
    if (n > 2)
    {
        for (int i = 1; i <= n - 2; i++)
        {
            Fn = Fn1 + Fn2;
            Fn2 = Fn1;
            Fn1 = Fn;
        }
        printf("%lu", Fn);
    }
    else
    {
        printf("1");
    }
}