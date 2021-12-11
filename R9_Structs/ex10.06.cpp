//10.06i

#include <iostream>
#include <cstdio>
using namespace std;


typedef struct {
    int n;
    double* arr;
} Vect;

Vect input() {
    Vect a;
    cout<<"n--> ";
    cin>>a.n;
    a.arr=(double*) malloc(a.n * sizeof *a.arr);
    for (int i=0; i<a.n; i++) {
        cout<<"a["<<i<<"]--> ";
        cin>>a.arr[i];
    }
    return a;
}

void print(Vect a) {
    cout<<"[";
    for (int i=0; i<a.n-1; i++) {
        cout<<a.arr[i]<<", ";
    }
    cout<<a.arr[a.n - 1]<<"]"<< endl;
}

void destroy(Vect a) {
    a.n=0;
    free(a.arr);
}


int main()
{
    Vect p=input();
    print(p);
    destroy(p);
    return 0;
}