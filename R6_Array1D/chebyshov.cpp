#include <iostream>
#include <iostream>
using namespace std;

float  Chebish( int n ,float x, float  *T_arr)
{
    float T0,T1;
    T0 = 1;
    T1 = x;

    for(int i = 2; i <= n; i++)
    {
        T_arr[i] = 2 * x * T1 - T0;
        T0 = T1;
        T1 = T_arr[i];

    }
    cout << T1;
    return 0;

}





int main()
{
    float x, T_arr[256];
    int n;
    printf("Enter x ");
    scanf("%f",&x);

    printf("Enter n ");
    scanf("%d",&n);

    cout << "The value of pol Chebishova in pow n = " << endl;
    Chebish(n, x, T_arr );
}
