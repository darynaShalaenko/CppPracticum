#include <iostream>
#include <cmath>

#include <Ratio.h>

using namespace std;




template<typename T> 
   T max2(T a[], int m){

    int n = m;// sizeof(a)/sizeof(a[0]);
     cout<<"n="<<n;
     if(m<=0) return -1;
    
    T s=a[0];
    for(int i=1;i<n;++i){
      if(s < a[i]){
         s= a[i];
      }
     } 
  return s;
} 

template<typename T, int m> 
   T max2(T a[]){

    int n = m;// sizeof(a)/sizeof(a[0]);
     cout<<"n="<<n;
     if(m<=0) return -1;
    
    T s=a[0];
    for(int i=1;i<n;++i){
      if(s < a[i]){
         s= a[i];
      }
     } 
  return s;
} 


template<typename T> 
   T summa(T a[], int m){

    int n = m;// sizeof(a)/sizeof(a[0]);
     cout<<"n="<<n;
    T s=0;
    for(int i=0;i<n;++i){
      s += a[i];
     } 
  return s;
} 



template<typename T, int m> 
   T summa2(T a[]){

    int n = m;// sizeof(a)/sizeof(a[0]);
     cout<<"n="<<n;
    T s=0;
    for(int i=0;i<n;++i){
      s += a[i];
     } 
  return s;
} 

template <typename T> T mod(T a[], int n) {
 T m = 0; 
 for (int i = 0; i < n; i++) { m += pow(a[i], 2); } 
 return static_cast<T>(sqrt(m)); 
} 


template <typename T> double mod(T a[], int n) {
 T m = 0; for (int i = 0; i < n; i++) { m += pow(a[i], 2); } 
return sqrt(m); }

int main(){

 int a[]={1,2,3,4,5};
 double b[]={1.0,2.3,3.14,2.5768};

 int s = summa2<int,5>(a);
 double s2 = summa(b,4);


 int s1 = max2<int,5>(a);
 double s11 = max2(b,4);

 Ratio mas[2];
 mas[0].set(1,2);
 mas[1].set(3,4); 
 Ratio z1 = max2<Ratio>(mas,2); 

 
  cout<<"s="<<s<<"; s2="<<s2<<endl;
  cout<<"s="<<s1<<"; s2="<<s11;


}
