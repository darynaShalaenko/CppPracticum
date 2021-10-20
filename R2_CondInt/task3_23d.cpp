#include <iostream>
using namespace std;

double sReLu(double tl, double tr, double al, double ar, double x){
    if (x<=tl) return tl+al*(x-tl);
    if (x>=tr) return tr+ar*(x-tr);
    return 0;
}

double sReLu_derivative(double tl, double tr, double al, double ar, double x){
    if (x<=tl) return al;
    if (x>=tr) return ar;
    return 0;
}

int main() {
    cout << " tl=? tr=? al=? ar=? x=? ";
    double tl,tr,al,ar,x; 
    cin>>tl>>tr>>al>>ar>>x;
    cout<<"sReLu()="<<sReLu(tl,tr,al,ar,x)<<endl;
    cout<<"sReLu_derivative()="<<sReLu_derivative(tl,tr,al,ar,x);


} 
