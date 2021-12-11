#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float eps;
    cout<<"eps-->";
    cin>>eps;
    float res=0.0;
    float el;
    int k=0;
    do
    {
        el=((pow(-1.0,k)/pow(4.0,k))*(2.0/(4.0*k+1.0)+2.0/(4.0*k+2.0)+1.0/(4.0*k+2.0)));
        res+=el;
        k+=1;
    } while (abs(el)>eps);
    cout<<"Pi="<<res<<endl;
    return 0;
}