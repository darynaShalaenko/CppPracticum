
#include <iostream>
#include <cmath>

using namespace std;
int pow2(unsigned long* a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        double sr = log(a[i])/log(2);
        if (sr == int (sr))
        {
            count++;
        }
    }
    return count;
}

int pow3(unsigned long* a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        double sr = log(a[i])/log(3);
        if (sr == int (sr))
        {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d",&n);
    if (n > 0) {
        unsigned long* arr = (unsigned long*) calloc(n, sizeof *arr);
        if(arr)
        {
            for(int i = 0; i<n; i++)
            {
                printf("arr[%d] = ",i);
                scanf("%lu",&arr[i]);
            }
            int p1 = pow2(arr,n);
            int p2 = pow3(arr,n);
            printf("pow2 = %d, pow3 = %d",p1,p2);
            free(arr);
        }
    }
    return 0;
}
