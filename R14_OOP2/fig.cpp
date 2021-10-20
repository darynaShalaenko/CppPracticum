#include <iostream>
#include <cmath>
using namespace std;

 // base abstract class
class Figure{

   public:
   //Figure(){}
   virtual double calculateVolume()=0;

   double getVolume(){
    return calculateVolume();
  }

//virtual double perimeter() = 0; // pure virtual method
 // void set(double r1) = 0;
 // virtual void set(double r1,double r2) = 0;

  virtual int input() = 0;
  
};


class Rectangle: public Figure{
   double a,b;
 
   public:
 double calculateVolume(){
     return a*b;
 }

  void set(double a1,double b1){
   a=a1;b=b1;
  }

  int input(){
     cout<<"a,b:"; cin>>a>>b;
  }

};

class Circle: public Figure{
  double r;

   public:
 double calculateVolume(){
     return M_PI*r*r;
 }

  void set(double r1){
   r=r1;
  }
  
  int input(){
    cout<<"R=";cin>>r;
  }
  

};

int main(){
  const size_t N = 3;

  Figure* a[N];

  for(int i=0;i<N;++i){
    string s;
    cout<<"(c)ircle or (r)ectangle?";
    cin>>s;
    if(s.length()>0 && s[0]=='c'){
     Circle* c= new Circle();
     //c->set(1); 
     c->input();
     a[i] = dynamic_cast<Figure*>(c); //->set(1);
     
     //a[i]->input(); 
   }
    else{
    // a[i].set(1,2);
     Rectangle* c= new Rectangle();
     c->set(1,2); 
     a[i] = dynamic_cast<Figure*>(c); //->set(1);
   }

  }

  double max=0;
  for(int i=0;i<N;++i){
    if(max<a[i]->getVolume()){
      max=a[i]->getVolume();
   }
 }

  cout<<max;

}
