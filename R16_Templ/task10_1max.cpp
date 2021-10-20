

#include <iostream>

#include <algorithm>

using namespace std;


namespace Max{

   template <class T>
   T max(T a, T b){
      cout<< "our max";
      return a>b?a:b;
   } 

}

int main(){

   int a1=2,b1=1;
   double a2=1.5; b2 =3.14;

   cout<<max(a1,b1)<<max(a2,b2);
   


}




