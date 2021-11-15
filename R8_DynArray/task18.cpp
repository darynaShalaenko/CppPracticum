
#include <iostream>
#include <cstdio>
using namespace std;

const int N=25 ;

void print(int a[N][N], int n) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout << a[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void input(int a[N][N], int n) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout<<"a["<<i+1<<"]"<<"["<<j+1<<"] = ";
            cin>>a[i][j];
        }
        //cout<<endl;
    }
}

void turn90(int a[N][N], int n) {
    int b[N][N];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            b[j][n-1-i]=a[i][j];
            //b[i][j]=a[j][n-1-i];
        }
    }
    print(b,n);
}


int main()
{
    int n;
    cout<<"n = ";
    cin>>n;
    n=2*n;
    int a[N][N];
    input(a,n);
    cout<<"Початкова матриця: \n" <<endl;
    print(a,n);
    cout<<"Отримана матриця в результаті повороту на 90 градусів: \n"<<endl;
    turn90(a,n);
    return 0;
}

