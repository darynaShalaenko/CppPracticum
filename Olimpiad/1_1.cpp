#include <iostream>
#include <string>
#include <map>
#include <vector>

/*
std::string derivative1(std::string polynome){

  std::map<int, int> pol;

  char a;
  int deg=0;
  int val=1;
  int sign=1;
  int state=0; // 0 -start, 1 read val, 2 read deg
  for(int i=0; i<polynome.size();++i){

  for(auto it = pol.begin();it!=pol.end();++it){
    std::cout<< it->second<<"*x^"<<it->first<<"+ ";

  }
     a = polynome[i];
     if(a=='+'){

       if(state==0){
         state =1;
       }
       else if(state=1){
         if(pol.find(0)!=pol.end()){
          pol[0] += val*sign; 
         }
         else{
          pol[0]=val*sign;
        }
      }   
      else{
        pol[deg] = val*sign;
        state= 0;
      }
      val =0;
      sign = 1;
     }
     else if(a=='-'){
       if(state==0){
         state =1;
       }
       if(state==0){
         state =1;
       }
       else if(state=1){
         if(pol.find(0)!=pol.end()){
          pol[0] += val*sign; 
         }
         else{
          pol[0]=val*sign;
         }
       }
       else{
        pol[deg] = val*sign;
        state= 0;
      }
       
      sign = -1;
     }
     else if(a=='x'){
         state=3;
        if(state==0){
          val=0;
        }
        
      
     }
     else if(a=='^'){
         state = 2;
         deg = 0;
         continue;
     }
     else if(a=='*'){
         state = 4;
         
         continue;
     }

     else{
        if(state==0){
          char buf[2];
          buf[0]= a; buf[1]='\0'; 
          val = atoi(buf);
          state=1;
        }
        else if(state==1){
          val *=10;//1*x^1+ 1*x^1+ diag2: 1, 2  a=2;

          char buf[2];
          buf[0]= a; buf[1]='\0'; 
          val += atoi(buf);
       }
       else{
          deg *=10;
          char buf[2];
          buf[0]= a; buf[1]='\0'; 
          deg += atoi(buf);
       }

    }    

   if(state==2){
       if(pol.find(0)==pol.end()){
        pol[deg] = val;
       }
       else{
        pol[deg] += val;
      }
   } 
   else if(state==3){
    if(pol.find(0)==pol.end()){
       pol[1] = val;
     }
     else{
      pol[1]+=val;
    } 
   }

   std::cout<<"diag"<<state<<": "<<val<<", "<<deg<<"  a="<<a<<";\n";
  for(auto it = pol.begin();it!=pol.end();++it){
    std::cout<< it->second<<"*x^"<<it->first<<"+ ";

  }
  std::cout<<"\n";
  }

  for(auto it = pol.begin();it!=pol.end();++it){
    std::cout<< it->second<<"*x^"<<it->first<<"+ ";

  }

  return std::string("");
}

*/
std::string derivative(std::string polynome){

  std::map<int, int> pol;

  std::vector<int> coef;

  char a;
  int deg=0;
  int val=0;
  int sign=1;
  int state=1; // 0 -start, 1 read val, 2 read deg
               // 5 - read deg ,    
  for(int i=0; i<polynome.size();++i){

    char a = polynome[i];
    if(state==0){
     if(a=='+'||a=='-'){
       state=1;
       val=0; 
       sign = (a=='-')?-1:1;
       continue; 
     }
     if(a=='x'){
        
      }
    }
    else if (state==1){
       if(a=='*') {
     state=0;val*=sign; 
     std::cout<<"val="<<val<<", "; 
      coef.push_back(val);
      continue;
     }
       else if(a=='x') {
       state=4;val=sign;
        std::cout<<"val="<<val<<", ";
        coef.push_back(val);
       continue;
       }
       if(a=='-' && i==0){
          val=-1;state=0;
          coef.push_back(val);
        std::cout<<"val="<<val<<", "; 
       continue;
     }
 
      if(a=='-'||a=='+'){
        val *=sign;
         deg=0;
       std::cout<<"val="<<val<<", ";
       std::cout<<"deg="<<deg<<", ";
          coef.push_back(val); 
       continue;
      } 
         
    }
    
    if(state==1){
       char buf[2];
         buf[0]= a; buf[1]='\0'; 
         val *= 10;
         val += atoi(buf);
       }

    if(a=='^'){
      state =5; continue;

   }

   if(state==4){
      if(a=='+'||a=='-'){
       deg=1;
       std::cout<<"deg="<<deg;
       deg=0;
     }

  }

    if(state==5){

       if(a=='+'||a=='-'){
           state=0;
           std::cout<<"deg="<<deg;
          deg=0;
          continue;
        }

       char buf[2];
         buf[0]= a; buf[1]='\0'; 
         deg *= 10;
         deg += atoi(buf);
       }

     if(a=='x'){
     state=4;
    }
  }

  if(state==1){
   val*=sign; 
   std::cout<<"val="<<val<<", ";
   coef.push_back(val);
  }
  else if(state==4){
  deg=1;
  std::cout<<"deg="<<deg<<", ";
   //coef.push_back(val);
 }
  
  std::cout<<"\n";
 return (std::string)"";
}

int main(){

std::string mas_test[] ={
"x^2+x",
//"2*x^100+100*x^2", "x^10000+x+1","-x^2-x^3",
//"x+x+x+x+x+x+x+x+x+x"
};

//derivative("x^2+x"); //2*x+1

//derivative("2*x^100+100*x^2");
/*
200*x^99+200*x
*/

for(std::string str :mas_test){
  derivative((std::string)str);

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
