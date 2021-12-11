//7.08г

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


double loga(double a, int b) {
    return log(a)/log(b);
}

int main()
{
    int N;
    cout<<"N-->";
    cin>>N;
    double a[N];
    int r=0;
    for (int i=0; i<N; i++) {
        double el;
        cout<<"a["<<i<<"]-->";
        cin>>el;
        if (loga(el,2)==round(loga(el,2))) r+=1; 
        a[i]=el;
    }
    cout<<r<<endl;
    return 0;
}
