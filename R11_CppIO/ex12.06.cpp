//12.06

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    int n;
    cout<<"n-->";
    cin>>n;
    double a[n];
    if (n>1) {
        int i=0;
        while (i<n-1){
            double x,r;
            cin>>x;
            cin.ignore(256,',');
            r=log(x);
            a[i]=r;
            i++;
        }
        double x,r;
        cin>>x;
        r=log(x);
        a[i]=r;
        for (int i=0;i<n;i++) {
            cout<<setprecision(5)<<fixed<<a[i]<<" ";
            cout<<setprecision(5)<<scientific<<a[i]<<endl;
        }
    }
    else {
        double x,r;
        cin>>x;
        r=log(x);
        a[0]=r;
        cout<<setprecision(5)<<fixed<<a[0]<<" ";
        cout<<setprecision(5)<<scientific<<a[0]<<endl;
    }
    return 0;
}