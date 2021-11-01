#include <iostream>
#include <vector>

#include<algorithm>

using namespace std;



void show(const vector<double> & v){
 
   vector<double>::const_iterator it;
   cout<<"<";
   for(it=v.begin();it!=v.end();++it){
       cout<< *it<<",";
   }  
   cout<<">"<<endl;
}

void input(vector<double> & v1){
    int n;
   cout<<"n=";
    cin>>n;
    double d;
    for(int i=0;i<n;++i){
         cin>>d;
       v1.push_back(d);
   }
   //show(v1);
}

vector<double> add(const vector<double> & v1, const vector<double> & v2){
      
   int m;   
   if(v1.size()!=v2.size()){
       cout<<"Vectors sizes dont match";
      
    }
   m = min(v1.size(), v2.size());
   vector<double> res(m); // size of vector - m

   for(int i=0;i<m;i++){
     res[i] = v1[i] + v2.at(i);
   }

   return res;
}


typedef vector<double> DoublePoly;

 
DoublePoly mult(DoublePoly v1, DoublePoly v2)
{
    int m1 = v1.size();
    int m2 = v2.size();

    int m3 = m1+m2-1;
    DoublePoly v3(m3);
    

    for(int i=0;i<m1;++i){
	 for(int j=0;j<m2;++j){
            v3[i+j] += v1[i]*v2[j];
       }

   }
  return v3; 
}

double scalar(const vector<double> &v1, const vector<double> &v2){
  if(v1.size() != v2.size()){ cout<<"Vector's sizes dont match"; } 
 int n = min(v1.size(), v2.size()); 
 double c = 0; 
 for(int i = 0; i < n; i++){ c += v1[i] * v2[i]; } 
 return c; } 

int main(){

   vector<double> v1,v2;

   input(v1);
   input(v2);

  DoublePoly z1(v1);

  DoublePoly z2(v2);

  show(z1);

  
  DoublePoly z3;
  z3 = mult(z1,z2);
  show(z3);
   
   vector<double> v3,v4;

   v3 = add(v1,v2);

   show(v3);
   double c = scalar(v1,v2);

   cout<<c<<endl;



}
