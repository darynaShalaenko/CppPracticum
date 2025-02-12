#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.0001  // DBL_EPSILON*2

int enter_arr(int *arr){
    int entered=0, counter=0;

    while (entered < 100)
    {
        printf("Enter value - ");
        scanf("%d", &entered);
        arr[counter] = entered;
        counter += 1;
        if(entered==0) break;
    }

    return counter;
}



int main()
{
    int n;
    int *arr, counter_root=0, counter_cubic=0;
    double root, cubic_root;

    arr = (int *)calloc(100, sizeof(int));

    n = enter_arr(arr);

    printf("\n\n");
    for(int i=0; i<n; i++)
    {
        root = sqrt(arr[i]);
        cubic_root = cbrt(arr[i]);
        if(fmod(root, (int)root) < EPS)
        {
            counter_root += 1;
        }
        if(fmod(cubic_root, (int)cubic_root) < EPS)
        {
            counter_cubic += 1;
        }
        //printf("%d %lf %lf\n", arr[i], root, cubic_root);
    }

    printf("Roots - %d\nCubic roots - %d", counter_root, counter_cubic);
    free(arr);
}
