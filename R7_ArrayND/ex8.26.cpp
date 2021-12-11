//8.26

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 15;

void print(int a[N][N], int n) {
    int i;
    int j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout << a[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
    
void input(int a[N][N], int n) {
    int i;
    int j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout<<"a["<<i<<"]"<<"["<<j<<"] --> ";
            cin>>a[i][j];
        }
        cout<<endl;
    }
}

void rotate(int a[N][N], int n) {
    int b[N][N];
    int i;
    int j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            b[j][n-1-i]=a[i][j];
        }
    }
    print(b,n);
}


int main()
{
    int n;
    cout<<"n --> ";
    cin>>n;
    int a[N][N];
    
    input(a,2*n);
    print(a,2*n);
    rotate(a,2*n);
    
    return 0;
}

