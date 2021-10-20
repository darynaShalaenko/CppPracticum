#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main()
{
    int i;
    int16_t num, r=0;
    cin>>num;
    //num=11;       //1011 1101
    cout<<bitset<16>(num)<<endl;

    for(i=0;i<16;i++){
        r |= ((num>>i) & 1)<<(15-i);
    }

    cout<<"Reversed binary: "<<endl;
    cout<<bitset<16>(r)<<endl;
    cout<<"Reversed decimal = "<<r<<endl;


