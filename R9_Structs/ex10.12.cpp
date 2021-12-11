//10.12

#include <iostream>
#include <cstdio>
using namespace std;

const int N=10;

typedef struct {
    double* arr;
} Product;

Product input() {
    Product a;
    a.arr=(double*) malloc(2 * sizeof *a.arr);
    cout<<"Гривень: ";
    cin>>a.arr[0];
    cout<<"Копійок: ";
    cin>>a.arr[1];
    return a;
}

void print(Product a) {
    cout<<a.arr[0]<<" гривень, "<<a.arr[1]<<" копійок."<<endl;
}

void destroy(Product a) {
    free(a.arr);
}

int convert_price(Product a) {
    return a.arr[0]*100+a.arr[1];
}

int main()
{
    int n;
    cout<<"Введіть к-ть товарів: ";
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cout<<"Товар №"<<i+1<<endl;
        Product p=input();
        int pr=convert_price(p);
        a[i]=pr;
        destroy(p);
    }
    int max_price=a[0];
    int m1=0;
    for (int i=0; i<n; i++) {
        if (a[i]>max_price) {
            max_price=a[i];
            m1=i+1;
        }
    }
    cout<<"Найдорожчий - товар №"<<m1<<endl;
    int min_price=a[0];
    int m2=0;
    for (int i=0; i<n; i++) {
        if (a[i]<min_price) {
            min_price=a[i];
            m2=i+1;
        }
    }
    cout<<"Найдешевший - товар №"<<m2<<endl;
    int sum=0;
    for (int i=0; i<n; i++) {
        sum+=a[i];
    }
    double average=sum/n;
    for (int i=0; i<n; i++) {
        if (abs(a[i]-average)<=1000) cout<<"товар №"<<i+1<<", ";
    }
    
    return 0;
}
