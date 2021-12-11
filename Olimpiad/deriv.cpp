#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string derivative(std::string polynome){

  //std::cout<<"pl="<<polynome<<"\n";

 std::string res = "";

  std::map<int, int,std::greater<int> > pol;

  std::vector<int> coef;

  std::vector<std::string> mon;
  std::vector<int> sign;
  char a;
  int deg=0;
  int val=0;
  //int sign=1;
  int state=1; // 0 -start, 1 read val, 2 read deg
               // 5 - read deg ,    
  std::string tok="";
  
  for(int i=0; i<polynome.size();++i){
    a = polynome[i];
    if(i==0 && a!='-' ){
       sign.push_back(1);
       }
    if(a=='+'||a=='-'){
       sign.push_back((a=='+')?1:-1);
       if(i==0) continue;
      //if(state==1){
       mon.push_back(tok);
        state=0; 
        tok="";
      //}
      //else if(state==0){
        tok = "";
        state=1;  
      //}
      
    }
    else{
      tok.push_back(a);
     }     
  }
  
  mon.push_back(tok);
   
  for(int i=0; i<mon.size();++i){
     std::string s= mon[i];
     //std::cout<<"tok="<<s<<"; "<<sign[i]<<";\t";
     int val, deg, k,m; 
     if(s.find("*x")!=std::string::npos){
        k = s.find_first_of('*');
        val = atoi(s.substr(0,k).c_str());
     }
     else{
          val = 1;
     }

     if(s.find("x^")!=std::string::npos){
        k = s.find_last_of('^');
       ////std::cout<<"r"<<s.substr(k+1,s.size()-1)<<"---";
        deg = atoi(s.substr(k+1,s.size()-1).c_str());
     }
     else if (s.find("x")!=std::string::npos){
          deg = 1;
     }
     else{
      deg=0;
   } 

     //std::cout<<"("<<deg<<",  "<<val<<")  ;; ";

     if(pol.find(deg)!=pol.end()){
      pol[deg] += sign[i]*val;
    }
    else{
      pol[deg] = sign[i]*val;
     }

  }

 //std::cout<<"\n\n\n\n";

   for(auto & pr: pol){
    if(pr.first==1){
       if(pr.second>0){
          //std::cout<<"+";
          res += "+";
       }
       //std::cout<<pr.second;
       res += std::to_string(pr.second);
    }
   else if(pr.first==2){
       if(pr.second>0){
          //std::cout<<"+";
          res += "+";
       }
      //std::cout<<pr.second * (pr.first)<<"*x";
      res += std::to_string(pr.second * (pr.first)) + "*x";
   }
    else if(pr.first>1){
      if(pr.second>0){
          //std::cout<<"+";
          res += "+";
       }
      //std::cout<<pr.second * (pr.first)<<"*x^"<<(pr.first-1);
      res += std::to_string(pr.second * (pr.first)) + "*x^" + std::to_string(pr.first-1);;
   }

   }

  //std::cout<<"\n";
  if(res.size()>=1 && res[0]=='+'){
   res = res.substr(1,res.size()-1);
 }
 return res;
}

int main(){

std::string mas_test[] ={
"x^2+x",
"2*x^100+100*x^2", "x^10000+x+1","-x^2-x^3",
"x+x+x+x+x+x+x+x+x+x"
};

//derivative("x^2+x"); //2*x+1

//derivative("2*x^100+100*x^2");
/*
200*x^99+200*x
*/

for(std::string str :mas_test){
  std::cout<< derivative((std::string)str);

  std::cout<<"\n";
 }

/*
Sample Output 3:

10000*x^9999+1

Sample Input 4:

-x^2-x^3

Sample Output 4:

-3*x^2-2*x

Sample Input 5:

x+x+x+x+x+x+x+x+x+x

Sample Output 5:

10
*/
   

}
