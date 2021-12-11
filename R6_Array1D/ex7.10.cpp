//7.10г

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout<<"n-->";
    cin>>n;
    int a[n];
    a[0]=0;
    int ela;
    for (int i=1; i<=n; i++) {
        cout<<"a"<<i<<"-->";
        cin>>ela;
        a[i]=ela;
    }
    int k=round(sqrt(n));
    int b[k];
    b[0]=0;
    for (int i=1; i<=k; i++) {
        b[i]=a[i*i];
    }
    int res=0;
    for (int i=1; i<=k; i++) {
        if (b[i]%2==0) res+=1;
    }
    cout<<res<<endl;
    return 0;
}
