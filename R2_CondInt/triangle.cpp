#include <iostream>


using namespace std;

void f(float r1, float r2,float r3, float xb,float yb,float xa,float ya,float xc,float yc,float x,float y){
    r1=(xb-xa)*(y-ya)-(x-xa)*(yb-ya);
    r2=(xc-xb)*(y-yb)-(x-xb)*(yc-yb);
    r3=(xa-xc)*(y-yc)-(x-xc)*(ya-yc);
    if ((r1>0 and r2>0 and r3>0) or (r1<0 and r2<0 and r3<0))
        cout<<"the point belongs to the triangle";
    else if ((r1==0 and r2*r3>0) or (r2==0 and r1*r3>0) or (r3==0 and r2*r1>0) or (x==xa and y==ya) or (x==xb and y==yb) or (x==xc and y==yc))
        cout<<"the point belongs to the side of the triangle";
    else
        cout<<"the point does not belong to the triangle";

}
int main() {
    float r1,r2,r3,xa,xb,xc,ya,yb,yc,x,y;

    cout<<"x=";
    cin>>x;
    cout<<"y=";
    cin>>y;

    cout<<"xa=";
    cin>>xa;
    cout<<"ya=";
    cin>>ya;

    cout<<"xb=";
    cin>>xb;
    cout<<"yb=";
    cin>>yb;

    cout<<"xc=";
    cin>>xc;
    cout<<"yc=";
    cin>>yc;
    f(r1,r2,r3,xb,yb,xa,ya,xc,yc,x,y);


}
