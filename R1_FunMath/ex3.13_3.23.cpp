#include <iostream>

using namespace std;

int onestep(double x){
    if (x>=0) return 1;
    else return 0;
}

int main()
{
    double a,b,c;
    cout<<"a-->";
    cin>>a;
    cout<<"b-->";
    cin>>b;
    cout<<"c-->";
    cin>>c;
    if (a==0 && b==0 && c!=0) cout<<"Немає"<<endl;
    else if (a==b && b==c && a==c) cout<<"Безліч"<<endl;
    else 
    {
        double x1,y1,x2,y2;
        cout<<"2 розв'язки:"<<endl;
        x1=(a-c)/(a-b)-1;
        y1=(-a+c)/(a-b);
        printf("(%.2f,%.2f)",x1,y1);
        cout<<endl;
        x2=(-a-c)/(a-b)+1;
        y2=(a+c)/(a-b);
        printf("(%.2f,%.2f)",x2,y2);
    }
    
    cout<<endl<<endl;
    double x;
    cout<<"x-->";
    cin>>x;
    cout<<onestep(x)<<endl;
    cout<<"Похідна = 0"<<endl;

    return 0;
}
