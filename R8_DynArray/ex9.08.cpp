//9.08

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


void input(double *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<"arr["<<i<<"] --> ";
        double el;
        cin>>*(arr+i);
    }
}

void print(double *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

double average(double *arr, int n) {
    double sum=0;
    for (int i=0; i<n; i++) {
        sum+=*(arr+i);
    }
    double aver;
    aver=sum/n;
    return aver;
}

void disper(double *arr, int n, double aver) {
    for (int i=0; i<n; i++) {
        cout<<abs(*(arr+i)-aver)<<" ";
    }
    cout<<endl;
}

int main () {
    int n;
    while (true) {
        cout<<"n --> ";
        cin>>n;
        if (n>0) {
            double *arr=new double[n];
            input(arr,n);
        
            print(arr,n);

            double aver=average(arr,n);
        
            disper(arr,n,aver);
        
            cout<<"Average --> "<<aver;

            delete [] arr;

            cout<<endl;
        }
        else
            break;
    };
    return 0;
}