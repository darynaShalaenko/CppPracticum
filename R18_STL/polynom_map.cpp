#include <iostream>

#include <map>

using namespace std;

class Polynom{

    map<int,double> coef;
    unsigned n;

   public:

    int set(int m, double val){
       coef[m] = val;
   } 

   void show(){
      map<int,double>::const_iterator it; 

      for(it=coef.begin();it!=coef.end();++it){
          //cout<<it->first<<":"<<it->second<<",";
         if(++it == coef.end()) break; 
         --it;
         int i = it->first;  
         cout<<coef[i]<<"x^"<<i<<"+";
      }
       int m = (--coef.end())->first;
       cout<<coef[m]<<"x^"<<m<<endl;

   }

   double get(int k) const{
    
    return coef.find(k)->second;
  }

   Polynom operator+(const Polynom & p){
	map<int,double>::const_iterator it; 
       Polynom answ;
      for(it=coef.begin();it!=coef.end();++it){
          //cout<<it->first<<":"<<it->second<<",";
         int i = it->first;  
         if(p.coef.find(i)==p.coef.end()){
           answ.coef[i] = coef[i];
	}
        else{
         answ.coef[i] = coef[i] + p.get(i);
        } 
      }

     for(it=p.coef.begin();it!=p.coef.end();++it){
          int i = it->first; 
          if(coef.find(i)==coef.end()){
           answ.coef[i] = p.get(i);
	}
     }
     
      return answ;
   }   

};


int main(){

   Polynom p1;

   p1.set(0,1.0);
   p1.set(2,1.0);
   p1.set(1,2.0);

   p1.show();

   Polynom p2,p3;

   p2.set(1,3.0);
   p2.set(3,2.0);

   p3 = p1+p2;

   p3.show();

 }
