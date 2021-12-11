#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double V(double R,double r)
{
    return (2* pow(M_PI,2)*R*pow(r,2));
}

double sigmweight(double x){
    return (x*pow((1+pow(M_E,-x)),-1));
}

double sigmweightpoh(double x){
    return ((1+(pow(M_E,-x))*(1+x))/(pow((1+pow(M_E,-x)),2)));
}


int main() {
    double R,r;
    cin>>R>>r;
    cout<<V(R,r)<<endl;
    
    double x;
    cin>>x;
    cout<<sigmweight(x)<<endl;
    cout<<sigmweightpoh(x)<<endl;
  
    return 0;
}