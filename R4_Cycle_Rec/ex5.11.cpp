#include <iostream>
#include <cmath>
using namespace std;

double ela(int k) {
    double a0,a1,a2,b0,b1,b2;
    a0=1;
    a1=2;
    b0=5;
    b1=5;
    for (int i=1;i<=k-1;i++) {
        b2=pow(b0,2)-a1;
        a2=b0+b2/2;
        a0=a1;
        a1=a2;
        b0=b1;
        b1=b2;
    }
    return a2;
}

double elb(int k) {
    double a0,a1,a2,b0,b1,b2;
    a0=1;
    a1=2;
    b0=5;
    b1=5;
    for (int i=1;i<=k-1;i++) {
        b2=pow(b0,2)-a1;
        a2=b0+b2/2;
        a0=a1;
        a1=a2;
        b0=b1;
        b1=b2;
    }
    return b2;
}

double sum(int n) {
    double s;
    if (n==1) s=0.4;
    else if (n==2) s=0.9146503;
    else 
    {
        s=0.9146503;
        for (int k=3;k<=n;k++) 
        {
            s+=pow((ela(k)/elb(k)),k);
        }
    }
    return s;
}

int main()
{
    int n;
    cout<<"n-->";
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}