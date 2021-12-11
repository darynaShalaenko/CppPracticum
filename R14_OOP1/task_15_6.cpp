
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Quadratic_equation {

public:
    double a;
    double b;
    double c;
    double arr[2]={0,0};
    int k;

    void solve() {
        if (a!=0 && b!=0) {
            double D=pow(b,2)-4*a*c;
            if (D<0) {
                cout<<"There are no solutions"<<endl;
                k=0;
            }   
            else if (D==0) {
                double x=(-b)/(2*a);
                cout<<"x="<<x<<endl;
                arr[0]=x;
                k=1;
            }
            else {
                double x1=(-b+pow(D,0.5))/(2*a);
                double x2=(-b-pow(D,0.5))/(2*a);
                cout<<"x1="<<x1<<endl<<"x2="<<x2<<endl;
                arr[0]=x1;
                arr[1]=x2;
                k=2;
            }
        }
        else if (a==0 && b==0) {
            if (c!=0) {
                cout<<"There are no solutions"<<endl;
                k=0;
            }
            else {
                cout<<"Infinite number of solutions"<<endl;
                k=0;
            }
        }
        else if (a==0) {
            double x=(-c)/b;
            cout<<"x="<<x<<endl;
            arr[0]=x;
            k=1;
        }
    }

    void find_increase() {
        if (a!=0) {
            double x0=(-b)/(2*a);
            if (a>0) {
                cout<<"["<<x0<<",+inf]"<<endl;
            }
            else {
                cout<<"[-inf,"<<x0<<"]"<<endl;
            }
        }
        else {
            if (b>0) {
                cout<<"[-inf,+inf]"<<endl;
            }
            else {
                cout<<"There are no increase intervals"<<endl;
            }
        }
    }

    void find_decrease() {
        if (a!=0) {
            double x0=(-b)/(2*a);
            if (a>0) {
                cout<<"[-inf,"<<x0<<"]"<<endl;
            }
            else {
                cout<<"["<<x0<<",+inf]"<<endl;
            }
        }
        else {
            if (b<0) {
                cout<<"[-inf,+inf]"<<endl;
            }
            else {
                cout<<"There are no decrease intervals"<<endl;
            }
        }
    }

    void find_extremum() {
        if (a!=0) {
            double x0=(-b)/(2*a);
            if (a>0) {
                double y0=a*pow(x0,2)+b*x0+c;
                cout<<"Minimum point: x="<<x0<<" y="<<y0<<endl;
            }
            else {
                double y0=a*pow(x0,2)+b*x0+c;
                cout<<"Maximum point: x="<<x0<<" y="<<y0<<endl;
            }
        }
        else {
            cout<<"There are no extremums"<<endl;
        }
    }
};

int main()
{
    Quadratic_equation one {4,3,1};
    Quadratic_equation two {1,16,0};
    Quadratic_equation three {13,-7,1};

    Quadratic_equation arr3[3]={one,two,three};

    arr3[0].solve();
    arr3[1].solve();
    arr3[2].solve();

    double arr_of_roots[6];


    int count=-1;
    for (int i=0;i<3;i++) {
        if (arr3[i].k==1) {
            count++;
            arr_of_roots[count]=arr3[i].arr[0];
        }
        else if (arr3[i].k==2) {
            count++;
            arr_of_roots[count]=arr3[i].arr[0];
            arr_of_roots[count+1]=arr3[i].arr[1];
            count++;
        }
        else
            continue;
    }

    for (int i=0; i<count+1;i++) {
        cout<<arr_of_roots[i]<<" ";
    }
    cout<<endl;

    double max=arr_of_roots[0];
    int i=0;
    while (i<6) {
        if(arr_of_roots[i]>=max) {
            max=arr_of_roots[i];
        }
        i++;
    }
    cout<<"Max root: "<<max<<endl;

    double min=arr_of_roots[0];
    int j=0;
    while (j<6) {
        if(arr_of_roots[j]<=min) {
            min=arr_of_roots[j];
        }
        j++;
    }
    cout<<"Min root: "<<min<<endl;

    return 0;
} 
