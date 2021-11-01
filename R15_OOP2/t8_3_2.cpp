
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
 protected:
 string name; //прізвище
 unsigned byear;//рік народження

 public:
int input(){
//ввести особу
 cout<<"input person";
cin>>name;
cin>>byear;
return 0;
}
void print(){
  cout<<name<<byear;
}
};



class Passanger : public Person
{
   string from;
   string to;

 public:
int input(){
   Person::input();
   cout<<"from/to";
   cin>>from;
   cin>>to;
  return 0;
}
/*
void print(){
    Person::print();
}*/

 bool dest_cmp(string x, string y){
    return (to == x) && (from == y);
 } 

};


class Dist{
   public:
   string from;
   string to;
   double dist;

   int input(){
   cout<<"input dist:"
   cin>>from;
   cin>>to;
   cin>>dist; 
   return 0;
  } 

  friend double Passanger::getPrice(double val, Passanger p){
     if ((to == p.to) && (from == p.y))
      return val * dist;
     return 0;
  }
};


int main(){

   int n,m;
    cout<<"n,m";
   cin>>n;
   cin>>m;
  Passanger *pas = new Passanger[n];

 for(int i=0;i<n;++i){
   pas[i].input();
 }

  vector<Dist> dst;

  for(int i=0;i<m;++i){
   Dist d; 
   d.input();
   dst.push_back(d);
 }
 double price;
 cout<<"Price for km:" 
 cin>>price;

 double sum=0;

  for(int i=0;i<n;++i){
   
     for(int j=0;j<m;++j){
      //if (pas[i].to == dst[j].to && pas[i].from == dst[j].from 
        if(pas[i].dest_cmp(dst[j].to, dst[j].from)){
            sum += price * dst[j].dist;
            break;
        }
     }
  }

 cout<< "sum="<<sum;

delete[] pas;
}

