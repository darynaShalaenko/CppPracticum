//9.09л(варіант 1)

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int** create_matrix(int N, int M) {
    int** a=(int**) malloc(N * sizeof *a);
    if (a==nullptr)
       exit(1);
    for (int i=0; i<N; i++) {
        a[i]=(int*) calloc(M, sizeof **a);
        if (a[i]==nullptr)
            exit(1);
    }
    return a;
}

void delete_matrix(int** a, int N) {
    for (int i=0; i<N; i++)
        free(a[i]);
    free(a);
}

int** input_matrix(int N, int M) {
    int** a=create_matrix(N, M);
    for (int i=0; i<N; i++) {
        cout<<"a["<<i<<"] = ";
        for (int j=0; j<M; j++) {
            cin>>a[i][j];
        }
    }
    return a;
}

void print_matrix(int** a, int N, int M) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int** delete_lines(int** a, int N, int M, int k1, int k2) {
    int l=k2-k1+1;
    int N1=N-l;
    int** c=create_matrix(N1, M);
    if (k1!=1 && k2!=N) {
        for (int i=0; i<k1-1; i++) {
            for (int j=0; j<M; j++) {
                c[i][j]=a[i][j];
            }
        }
        int r1=k1-2;
        for (int i=k2; i<N; i++) {
            r1++;
            for (int j=0; j<M; j++) {
                c[r1][j]=a[i][j];
            }
        }
    }
    else if (k1==1 && k2!=N) {
        int r2=-1;
        for (int i=k2; i<N; i++) {
            r2++;
            for (int j=0; j<M; j++) {
                c[r2][j]=a[i][j];
            }
        }
    }
    else if (k1!=1 && k2==N) {
        for (int i=0; i<k1-1; i++) {
            for (int j=0; j<M; j++) {
                c[i][j]=a[i][j];
            }
        }
    }
    return c;
}

int main() {
    int N,M,k1,k2;
    cout<<"N--> ";
    cin>>N;
    cout<<"M--> ";
    cin>>M;
    int** a=input_matrix(N, M);
    
    print_matrix(a, N, M);

    cout<<"k1--> ";
    cin>>k1;
    cout<<"k2--> ";
    cin>>k2;
    
    int** c=delete_lines(a, N, M, k1, k2);
    int N1=N-(k2-k1+1);
    print_matrix(c, N1, M);

    delete_matrix(a,N);
    delete_matrix(c,N1);

    return 0;
}




