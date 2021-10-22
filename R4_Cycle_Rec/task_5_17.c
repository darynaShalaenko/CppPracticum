#include <iostream>
#include <bitset>
#include <climits>
using namespace std;



int main()
{
    //a)
    int k,i,len_s;

    i = 0;
    len_s = 0;
    printf("Enter k ");
    scanf("%d",&k);

    do
    {
        i += 1;
        len_s += i;
    }while (len_s < k);

    if((i -1) == (len_s - k))
    {
        cout << 1;
    }else{cout << 0;}
}

/*
//b)
int main()
{
int		c, d, k, j, n, z;
printf("Enter k ");
scanf("%d",k);
c = n = 0;
do {
n++;
for ( d = 1, j = n; j /= 10; d++ );
c += d;
} while ( c < k );
for ( z = c - k; z--; n /= 10 );
cout << "Result: " << n % 10 << endl;
return 0;
}

