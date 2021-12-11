#include <iostream>
using namespace std;

long double factorial(int k)
{
    if (k==0) 
        return 1; 
    else 
        return k*factorial(k-1); 
}

long double power(float x,int k)
{
    float res=1;
    for (int i=0;i<k;i++)
    {
        res*=x;
    }
    return res;
}

int main()
{
    int k;
    float x;
    cout<<"k-->";
    cin>>k;
    cout<<"x-->";
    cin>>x;
    cout<<"xk="<<power(-1,k)*power(x,k)/factorial(k)<<endl;
    return 0;
}