
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


class Polynome{

     size_t n;
     double* a; // a_n * x^n + ...+ a_1*x^1 + a_0 

     public:

     Polynome(){
      n=0;
      cout<<"Empty constructor"<<endl;
      //a = new double[1];
     }


     Polynome(const Polynome& p){
       cout<<"Copy constructor"<<endl;
      n=p.n;
      a = new double[p.n+1];
       for(int i=0;i<n+1;++i){
       		a[i]=p.a[i];
   	}
       
     }     

     Polynome(int n1){
      cout<<"Constructor with new"<<endl;
      n=n1;
      a = new double[n+1];
     }     

     Polynome(size_t n1, double* ar){
        n = n1;
         try{
         	a = new double[n1+1];  
          cout<<"Constructor with New";
	}
        catch(...){
          cout<<"Error locating n="<<n1<<" doubles";
        }
         
         //memcpy(a,ar,sizeof(*a)*(n+1)); // Copy array a=ar;
    	for(int i=0;i<n+1;++i){
       		a[i]=ar[i];
   	}
      show();
    }
     
    virtual ~Polynome(){
      cout<<"Destructor";
      if ( n>0 and a!=NULL){
         cout<<"\n Free:";
         show();

      	delete[] a;
	}

    }

    Polynome& operator=(const Polynome & p){
       n=p.n;
       a = new double[p.n+1];
       for(int i=0;i<n+1;++i){
       		a[i]=p.a[i];
   	}
       
    return *this;
   }


   double value(double x){
        double y=0;
  	for(int i=0;i<n+1;++i){
       		y+= a[i]* pow(x,i);
   	}
  }


   double value2(double x){
        double y=0;
  	for(int i=n;i>=1;++i){
       		y+= a[i];
                y *=x;
   	}
        y +=a[0];
       return y;
  }

  Polynome& operator+ (Polynome & x){

    size_t M = max(x.n,n);    

     Polynome* z = new Polynome(M);

    if(x.n>=n){
    	for(int i=0;i<n+1;++i){
          z->a[i] = x.a[i] + a[i];
       }
       for(int i=n+1;i<M+1;++i){
          z->a[i] = x.a[i];
       }
    }
    else{
    for(int i=0;i<x.n+1;++i){
          z->a[i] = x.a[i] + a[i];
       }
       for(int i=x.n+1;i<M+1;++i){
          z->a[i] = a[i];
       }

   }
   //cout<<"y="<<y[0];
 
   return *z;
  }


Polynome operator* (const Polynome & x){

     size_t M = x.n + n;
     //cout<<"M="<<M;    
    Polynome z(M);
 
    for(int i=0;i<=M;++i){
          z.a[i] = 0;
       }

    for(int i=0;i<=n;++i){
	    for(int j=0;j<=x.n;++j){
          	z.a[i+j] += x.a[j] * a[i];
	    }
       }
 
   return Polynome(z);

}

    void show(){
    	for(int i=n;i>0;--i){
       		cout<<a[i]<<"*"<<"x^"<<i<<"+";
   	}
       cout<<a[0]<<endl;
   }

 

};

int main(){

   double a1[5] ={1,2,3,4,5}; 
   Polynome p1;

   Polynome p2(2,a1);

   p2.show();

   Polynome p3(3,a1);

   p1 = p2+p3;
   cout<<"Sum=";
   p1.show();
  cout<<"Val=";
   cout<< p2.value(1)<<endl;

   Polynome p4;

   p4 = p3*p2;
   p4.show();

}

