#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int n,k, count;
    printf("Enter the size ");
    scanf("%d",&n);
    int arr[n];
    count = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for( int i = 1; i <= sqrt(n); i++ )
    {
        if((arr[i*i] % 2) == 0)
        {
            count += 1;
            cout << arr[i*i] << " ";
        }
    }

    printf("\nThe count = %d",count);


} 
