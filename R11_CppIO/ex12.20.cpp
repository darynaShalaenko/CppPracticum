//12.20

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    ifstream finp;
    finp.open("input12.20.txt");
    double x;
    double y;
    double m;
    double res;
    double max1=0;
    double max2=0;
    double xm1=0;
    double ym1=0;
    double mm1=0;
    double xm2=0;
    double ym2=0;
    double mm2=0;
    
    while (true) {
        finp.ignore(256,'[');
        if (!finp.good())
            break;
        finp>>x;
        finp.ignore(256,',');
        finp>>y;
        finp.ignore(256,',');
        finp>>m;
        res=m*(x+y);
        if(res>max1) {
            max2=max1;
            xm2=xm1;
            ym2=ym1;
            mm2=mm1;
            max1=res;
            xm1=x;
            ym1=y;
            mm1=m;
        }
    }
    cout<<"["<<xm1<<","<<ym1<<","<<mm1<<"]"<<endl;
    cout<<max1<<endl;
    cout<<"["<<xm2<<","<<ym2<<","<<mm2<<"]"<<endl;
    cout<<max2;
    finp.close();
    return 0;
}
