#include <iostream>
#include <cmath>
using namespace std;

double fact(int x) {
    if (x==0) 
        return 1; 
    else 
        return x*fact(x-1); 
}

double ln(double x,double eps) {
    int i=1;
    double s=0;
    double el;
    do {
        el=pow(-1,i+1)*pow(x,i)/(fact(i));
        s+=el;
    } while (abs(el)>=eps);
    return s;
}

int main()
{
    double eps;
    cout<<"eps --> ";
    cin>>eps;
    double x;
    cout<<"|x|<1 --> ";
    cin>>x;
    cout<<ln(x,eps)<<endl;
    return 0;
}