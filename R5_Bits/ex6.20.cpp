//6.20

#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int16_t toz(uint16_t m, uint16_t j) {
    int16_t k;
    m=~m;
    k=1<<j; 
    m=m|k;
    m=~m;
    return m;
}

int main() {
    uint16_t n,i;
    int16_t k,p,r;
    cout<<"n-->";
    cin>>n;
    cout<<bitset<16>(n)<<endl;
    cout<<"i-->";
    cin>>i;
    k=n>>i+1;
    cout<<"k=n>>i+1;"<<endl;
    cout<<bitset<16>(k)<<endl;
    k=k<<i;
    cout<<"k=k<<i;"<<endl;
    cout<<bitset<16>(k)<<endl;
    p=n<<(16-i);
    cout<<"p=n<<16-i;"<<endl;
    cout<<bitset<16>(p)<<endl;
    p=p>>1;
    cout<<"p=p>>1;"<<endl;
    cout<<bitset<16>(p)<<endl;
    p=toz(p,15);
    cout<<"p=toz(p,15);"<<endl;
    cout<<bitset<16>(p)<<endl;
    p=p>>15-i;
    cout<<"p=p>>15-i;"<<endl;
    cout<<bitset<16>(p)<<endl;
    r=p|k;
    cout<<"r=p|k;"<<endl;
    cout<<r<<endl;
    cout<<bitset<16>(r)<<endl;
    //cout<<r<<endl;
    return 0;
}

