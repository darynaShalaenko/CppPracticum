#include <iostream>

using namespace std;

double el(int i) {
    if (i==0) return 1;
    else if (i==1) return 0.3;
    else return (i+2)*el(i-2);
}

int main()
{
    int i;
    cout<<"i-->";
    cin>>i;
    printf("v%i=",i);
    cout<<el(i)<<endl;
    return 0;
}